# DockerReport

Calculates various counts on a Docker projects, including number of platforms, etc.

Input is a YAML file, dockercompose.yml. An example dockercompose.yml is included.

The DockerReport main program includes code to directly parse YAML interleaved with code
to produce the report.

Notes:
* The integrated YAML parser does not handle all parts of YAML
