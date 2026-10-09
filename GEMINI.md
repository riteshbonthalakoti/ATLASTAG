# AtlasTag — Workspace Engineering Rules

You are the engineering assistant for **AtlasTag**, a hardware asset-tracking project developed for Hack Club Half Life. Follow these rules for all operations in this workspace.

---

## 1. Project Purpose & Scope Boundary

- **Project Definition:** AtlasTag is a compact, battery-powered asset tracker combining GNSS, cellular connectivity, motion sensing, and efficient power management.
- **V1 Candidate Capabilities:**
  - GNSS positioning.
  - LTE-M / NB-IoT connectivity, subject to verified hardware platform support and regional network compatibility.
  - Motion-triggered wake-up via low-power accelerometer interrupt.
  - Battery voltage and state-of-charge monitoring.
  - Local SPI NOR Flash storage for store-and-forward telemetry, subject to final architectural validation.
- **Scope Gate:** Do not automatically add BLE, Wi-Fi positioning, UWB, geofencing, or TinyML to V1. Any feature expansion requires an explicit scope review, budget justification, and user approval.

---

## 2. Hardware Decisions & Evidence

- **Platform Status:** Keep the primary Cellular/GNSS platform decision **OPEN** until evidence-based research and trade study evaluations are completed and reviewed.
- **BOM vs. Design Decisions:** Do not treat preliminary BOM entries as finalized design commitments.
- **Verification Criteria:** Before selecting any component, verify:
  - Absolute maximum electrical limits and operating supply voltages.
  - Package physical dimensions and pitch manufacturability.
  - Pin assignments and interface electrical types (do not invent footprints or assume pin compatibility).
  - Power consumption in active, sleep, and peak transmission modes.
  - Digital interfaces (I2C, SPI, UART, GPIO interrupts).
  - RF matching requirements, impedance tolerance, and antenna keepouts.
  - Distributor availability and lead times.
- **Decision Tracking:** Record all candidate trade-offs, datasheets, and selection rationale in `docs/decisions/DECISION_LOG.md`.
- **PCB Stackup & Geometry:** Do not prescribe a PCB layer count, dielectric stackup, or RF coplanar waveguide geometry until the selected silicon package and fabrication constraints justify it.

---

## 3. Budget & Bill of Materials

- **Funding Limit:** Half Life Tier 3 parts funding target is **$100.00 USD** (~₹8,350 INR).
- **Dual-Currency Tracking:** Maintain prices in both **USD ($)** and **INR (₹)** based on verified distributor sources.
- **Precision:** Record exact Manufacturer Part Numbers (MPNs), quantities, distributor source URLs, retrieval dates, and explicit assumptions.
- **Cost Separation:** Distinguish bare component costs from shipping fees, taxes/import duties, assembly costs, and contingency margins.
- **File Roles:**
  - `bom/BOM.md` is the authoritative detailed engineering BOM.
  - Root `BOM.md` is a Half Life platform mirror. Do not overwrite or modify Half Life-generated sync blocks; append custom documentation only where supported.

---

## 4. EDA & KiCad Guidelines

- **Tool of Record:** KiCad 10.0.6 (where supported by the installed environment).
- **Absolute CLI Path:**
  ```text
  C:\Users\bonth\AppData\Local\Programs\KiCad\10.0\bin\kicad-cli.exe
  ```
- **CLI Automation:** Always invoke KiCad tools using the verified absolute executable path. Do not assume or require changes to the Windows system `PATH`.
- **Pre-execution Verification:** Verify that project, schematic (`*.kicad_sch`), or PCB (`*.kicad_pcb`) files actually exist before running CLI commands.
- **Validation Integrity:**
  - Run electrical rules checks (ERC) and design rules checks (DRC) only when actual design files exist.
  - Inspect raw CLI command output. Report all warnings and errors factually; never claim zero violations without inspecting the actual report.
  - Successful ERC/DRC does not prove RF performance, battery life, or regulatory compliance.
  - Never generate production fabrication outputs (Gerbers, drill files, BOMs) from an unverified design.

---

## 5. Git & Version Control

- **Branch Model:**
  - `dev` is the active development branch.
  - `main` is the stable baseline branch.
- **Pull Requests:** Changes move from `dev` to `main` strictly through reviewed pull requests. Never auto-merge.
- **Safe Operations:** Never force-push (`--force`) to remote branches. Never discard working-tree changes without explicit confirmation.
- **Commits:** Use Conventional Commit syntax (`feat:`, `fix:`, `docs:`, `chore:`).
- **Identity:** Use the user's configured Git identity. Do not add AI co-author attributions.
- **Approvals:** Never push commits, open pull requests, merge branches, or alter GitHub repository settings without explicit user approval.
- **Inspection:** Check `git status` before and after all file operations.

---

## 6. Documentation & Factual Reporting

- **Consistency:** Maintain technical alignment across:
  - `README.md`
  - `docs/requirements/REQUIREMENTS.md`
  - `docs/architecture/ARCHITECTURE.md`
  - `docs/research/RESEARCH_INDEX.md`
  - `docs/decisions/DECISION_LOG.md`
  - `bom/BOM.md`
  - `docs/environment/ENVIRONMENT.md`
- **Contradictions:** Do not silently resolve conflicting specifications. Highlight discrepancies and resolve them through primary evidence.
- **Honest Logging:** Never fabricate devlog entries, tracked hours, timelapse links, screenshots, test results, or personal reflections. Provide factual, unembellished summary notes that the user can review and rewrite in their own voice.
- **Mirror Integrity:** Do not edit Half Life-generated sections in `JOURNAL.md` or root `BOM.md`.
