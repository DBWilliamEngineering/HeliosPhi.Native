# HelioPhi.Native

**Native C++ runtime for Intel Xeon Phi coprocessors.**

HelioPhi.Native is the native hardware and runtime layer of the HelioPhi project. It is intended to provide a modern C++ foundation for communicating with and executing workloads on Intel Xeon Phi coprocessors, with initial development focused on the Intel Xeon Phi 5110P and the Knights Corner generation.

The project exists to make legacy Xeon Phi hardware more approachable from a modern development environment while keeping Intel-specific runtime and device concerns isolated from higher-level applications.

## Overview

Intel Xeon Phi was designed as a many-core coprocessor platform for highly parallel workloads. While the hardware remains useful for experimentation, education, research, and specialized compute workloads, much of its original software ecosystem was built around tooling and operating environments that are now significantly dated.

HelioPhi.Native provides the low-level native foundation for the broader HelioPhi ecosystem. It is responsible for the host-side interaction required to discover, initialize, communicate with, and execute work on supported Xeon Phi hardware.

A companion managed project, **HelioPhi.Managed**, will provide a modern .NET interface over the native runtime so that applications can use Xeon Phi hardware without directly depending on Intel's legacy APIs.

## Goals

The primary goals of HelioPhi.Native are:

- Provide a clean, maintainable modern C++ foundation for Intel Xeon Phi interaction.
- Support communication between a modern Windows host and supported Xeon Phi coprocessors.
- Provide the native functionality required by the HelioPhi managed .NET SDK.
- Handle device discovery, initialization, communication, memory management, workload execution, and diagnostics.
- Isolate legacy Intel MPSS and SCIF dependencies from higher-level applications.
- Provide reliable diagnostic and benchmarking capabilities for validating hardware and runtime behavior.
- Establish a foundation for reusable workloads designed around Xeon Phi's many-core architecture.
- Favor clear ownership, predictable resource management, and testable components as the project develops.

## Current Scope

Development is currently focused on:

- Intel Xeon Phi 5110P
- Knights Corner architecture
- Windows 11 as the host development environment
- Intel MPSS / SCIF-based device communication
- Native C++ runtime development
- Integration with the HelioPhi managed .NET SDK

Support for additional Xeon Phi models or environments may be explored later as the project matures.

## Project Status

HelioPhi.Native is currently in **early development**.

Initial work is focused on hardware bring-up, device discovery, establishing reliable host-to-coprocessor communication, and validating the execution path before higher-level compute functionality is introduced.

The API and internal implementation should be considered unstable until the initial runtime architecture has been proven against physical hardware.

## HelioPhi

HelioPhi is divided into three primary projects:

**HelioPhi.Native**  
The native C++ runtime responsible for direct interaction with Intel Xeon Phi hardware.

**HelioPhi.Managed**  
The managed .NET SDK that provides a modern C# interface over HelioPhi.Native.

**HelioPhi.Samples**  
Sample applications, benchmarks, and reference workloads demonstrating the HelioPhi SDK.

## License

Copyright © 2026 Damon Bushong.

HelioPhi.Native is licensed under the **PolyForm Strict License 1.0.0**.

The license permits use for noncommercial purposes, including personal study, research, experimentation, hobby projects, and qualifying educational or other noncommercial organizational use.

The license does **not** grant permission to modify the software, create derivative works based on it, or distribute copies of it. Commercial use is also outside the granted license.

Any use beyond the rights granted by the PolyForm Strict License requires separate permission from the copyright holder.

See [LICENSE.md](LICENSE.md) for the complete license terms.
