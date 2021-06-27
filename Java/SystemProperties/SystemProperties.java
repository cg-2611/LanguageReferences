public class SystemProperties {

	private SystemProperties() {}

	public static String getOperatingSystemName() {
		return System.getProperty("os.name");
	}

	public static String getOperatingSystemArchitecture() {
		return System.getProperty("os.arch");
	}

	public static String getOperatingSystemVersion() {
		return System.getProperty("os.version");
	}

	public static String getJavaVersion() {
		return System.getProperty("java.version");
	}

	public static String getJavaHome() {
		return System.getProperty("java.home");
	}

	public static String getUserHomeDirectory() {
		return System.getProperty("user.home");
	}

	public static String getUserCountry() {
		return System.getProperty("user.country");
	}

	/*
	 *  All system properties, outputted by: System.getProperties().list(System.out);
	 *
	 *  gopherProxySet
	 *  awt.toolkit
	 *  java.specification.version
	 *  sun.cpu.isalist
	 *  sun.jnu.encoding
	 *  java.class.path
	 *  java.vm.vendor
	 *  sun.arch.data.model
	 *  java.vendor.url
	 *  user.timezone
	 *  os.name
	 *  java.vm.specification.version
	 *  sun.java.launcher
	 *  user.country
	 *  sun.boot.library.path
	 *  sun.java.command
	 *  http.nonProxyHosts
	 *  jdk.debug
	 *  sun.cpu.endian
	 *  user.home
	 *  user.language
	 *  java.specification.vendor
	 *  java.version.date
	 *  java.home
	 *  file.separator
	 *  java.vm.compressedOopsMode
	 *  line.separator
	 *
	 *  java.specification.name
	 *  java.vm.specification.vendor
	 *  java.awt.graphicsenv
	 *  sun.management.compiler
	 *  ftp.nonProxyHosts
	 *  java.runtime.version
	 *  user.name
	 *  path.separator
	 *  os.version
	 *  java.runtime.name
	 *  file.encoding
	 *  java.vm.name
	 *  java.vendor.url.bug
	 *  java.io.tmpdir
	 *  java.version
	 *  user.dir
	 *  os.arch
	 *  java.vm.specification.name
	 *  java.awt.printerjob
	 *  sun.os.patch.level
	 *  java.library.path
	 *  java.vm.info
	 *  java.vendor
	 *  java.vm.version
	 *  sun.io.unicode.encoding
	 *  java.class.version
	 *  socksNonProxyHosts
	 */

}
