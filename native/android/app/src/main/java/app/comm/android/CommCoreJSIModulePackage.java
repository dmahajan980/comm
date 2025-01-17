package app.comm.android;

import app.comm.android.fbjni.CommHybrid;
import com.facebook.react.bridge.JSIModuleSpec;
import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;
import com.swmansion.reanimated.ReanimatedJSIModulePackage;
import java.util.Collections;
import java.util.List;

public class CommCoreJSIModulePackage extends ReanimatedJSIModulePackage {

  @Override
  public List<JSIModuleSpec> getJSIModules(
      ReactApplicationContext reactApplicationContext,
      JavaScriptContextHolder jsContext) {
    CommHybrid.initHybrid(reactApplicationContext);
    super.getJSIModules(reactApplicationContext, jsContext);
    return Collections.emptyList();
  }
}
