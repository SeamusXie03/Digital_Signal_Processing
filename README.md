# Digital Signal Processing Project

## Overview

Welcome to the Digital Signal Processing Project! In this project, we explore the implementation of various signal processing techniques on a Field-Programmable Gate Array (FPGA). The project covers topics such as Nios, Qsys, DDS (Direct Digital Synthesis), LFSRs (Linear Feedback Shift Registers), Modulations (ASK, BPSK, FSK), and clock domain crossing.

This project provides a comprehensive hands-on experience with FPGA development, real-time signal processing, and integration of components to create a VGA oscilloscope for signal visualization.

## Project Components

### Implemented Features

- **LFSR and Clock:** A 5-bit LFSR is instantiated, generating a pseudo-random bit sequence. Clock generation at 1 Hz from CLOCK_50 is achieved using a clock divider.

- **DDS (Direct Digital Synthesis):** The DDS module is instantiated, generating a 3 Hz carrier sine wave. The DDS tuning word is calculated to achieve the desired frequency.

- **Modulation:** The DDS is modulated using the LFSR to generate ASK (OOK) and BPSK signals. Proper clock domain crossing is implemented for signal integrity.

- **VGA Oscilloscope:** Modulated signals and DDS outputs are connected to the VGA oscilloscope. The VGA interface allows visualization of signals in real-time.

- **FSK (Frequency Shift Keying):** A hybrid software/hardware approach is employed to generate FSK signals. The Nios processor responds to LFSR interrupts, adjusting DDS tuning words for FSK modulation.

- **QPSK Modulation:** Quadrature Phase Shift Keying (QPSK) modulation is implemented, enhancing signal diversity.

- **Audio Functionality:** The project includes optional audio functionality. Songs can be played, paused, and switched using the graphical user interface.

- **Graph Color Customization:** Nios PIOs, buttons, and software enable users to change the colors of the graphs for a personalized experience.

## Getting Started

### Prerequisites

- Quartus Prime software for FPGA development.
- FPGA board compatible with Quartus Prime.
- VGA screen and input devices for the FPGA board.

### Installation and Setup

1. Clone the project repository.
2. Open the Quartus project file (`.qpf`) in Quartus Prime.
3. Compile the project to generate the `.sof` file.
4. Program the FPGA board using the generated `.sof` file.
5. Load the Nios software using the provided `.elf` file.
6. Run the project on the FPGA.
