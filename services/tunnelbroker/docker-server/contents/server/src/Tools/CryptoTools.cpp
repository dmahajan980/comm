#include "CryptoTools.h"

#include <cryptopp/base64.h>
#include <cryptopp/cryptlib.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <cryptopp/pssr.h>
#include <cryptopp/rsa.h>
#include <cryptopp/whrlpool.h>

#include <iostream>

namespace comm {
namespace network {
namespace crypto {

bool rsaVerifyString(
    const std::string &publicKeyBase64,
    const std::string &message,
    const std::string &signatureBase64) {
  bool result = false;
  using Verifier =
      CryptoPP::RSASS<CryptoPP::PSSR, CryptoPP::Whirlpool>::Verifier;
  CryptoPP::Base64Decoder *base64Dec = new CryptoPP::Base64Decoder();
  CryptoPP::RSA::PublicKey publicKey;
  publicKey.Load(
      CryptoPP::StringSource(publicKeyBase64, true, base64Dec).Ref());
  std::string decodedSignature;

  CryptoPP::StringSink *strSing = new CryptoPP::StringSink(decodedSignature);
  base64Dec = new CryptoPP::Base64Decoder(strSing);
  CryptoPP::StringSource decodedSignatureSource(
      signatureBase64, true, base64Dec);

  Verifier verifier(publicKey);
  CryptoPP::ArraySink *arrSink =
      new CryptoPP::ArraySink((CryptoPP::byte *)&result, sizeof(result));
  CryptoPP::SignatureVerificationFilter *verificationFilter =
      new CryptoPP::SignatureVerificationFilter(verifier, arrSink);
  CryptoPP::StringSource signatureVerificationSource(
      decodedSignature + message, true, verificationFilter);

  delete strSing;
  delete base64Dec;
  delete arrSink;
  delete verificationFilter;

  return result;
}

} // namespace crypto
} // namespace network
} // namespace comm
