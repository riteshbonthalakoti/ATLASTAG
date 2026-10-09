---
name: atlas-bom-audit
description: >-
  Audit and verify the AtlasTag Bill of Materials (BOM), cross-checking part numbers, footprints,
  stock availability, distributor pricing in USD and INR, and budget compliance against Half Life limits.
  Use during component updates, price verifications, or pre-milestone reviews.
---

# AtlasTag Bill of Materials (BOM) Audit Procedure

Use this skill to inspect, audit, and validate component selections, pricing, and budget allocations in `bom/BOM.md` and root `BOM.md`.

---

## Operating Guidelines

- **Fact-Based Pricing:** Never claim a live price check unless actual distributor web tools were run. When estimating, explicitly label entries as "Estimates".
- **Half Life Mirror Preservation:** Never overwrite or corrupt the automated sync sections in root `BOM.md`. The detailed engineering BOM resides in `bom/BOM.md`.
- **Budget Tracking:** Track all items against the **$100.00 USD** (~₹8,350 INR) Half Life Tier 3 parts limit.

---

## Step-by-Step Procedure

### 1. Inspect Authoritative BOM
- Read `bom/BOM.md`.
- Verify each line item contains:
  - Reference Designator (`RefDes`).
  - Subsystem role.
  - Manufacturer Name.
  - Full Manufacturer Part Number (`MPN`).
  - Package / Footprint code.
  - Quantity per board (`Qty`).
  - Unit Price in Indian Rupees (`INR ₹`).
  - Unit Price in US Dollars (`USD $`).
  - Primary sourcing distributor link.

### 2. Verify Part Numbers & Footprints
- Cross-check that the MPN ordering code matches the intended footprint (e.g., tape-and-reel suffix `-R` vs. cut tape, temperature ratings, voltage suffix).
- Verify footprint geometry matches standard IPC libraries or manufacturer recommended landing patterns.

### 3. Verify Distributor Pricing & Availability
- Check authorized distributor listings (Mouser India, DigiKey India, Robu.in, Evelta):
  - Confirm part is marked "In Stock" or has acceptable lead times.
  - Record price at quantity = 1 (or relevant prototype quantity).
  - Record the date of retrieval and currency exchange rate used.
- Account for Indian procurement logistics:
  - Mouser India: 18% GST business invoice eligible; free shipping threshold (₹4,000 / ~$50).
  - DigiKey India: Free shipping threshold (₹7,000 / ~$85).
  - Domestic suppliers (Robu.in): Mandatory for Li-Po batteries to prevent IATA DG air cargo rejection.

### 4. Mathematical Audit & Classification
- Recalculate all line-item extended costs: $\text{Total} = \text{Qty} \times \text{Unit Price}$.
- Sum the core BOM subtotal in both USD and INR.
- Separate expenses into clear categories:
  - **Verified Component Costs:** Live quotes from authorized distributors.
  - **Estimated Passives / Hardware:** Labeled estimates (e.g., generic 0402 caps/resistors).
  - **Manufacturing Spares & Fab:** Prototype PCB fabrication (5 pcs), SMD stencils.
  - **Contingency Reserve:** Unallocated balance.

### 5. Generate Audit Report
Provide a structured audit report to the user:
- Current Core BOM Total vs. $100.00 funding limit.
- Remaining budget headroom.
- Component risks (single-source items, low stock, lead time warnings).
- Out-of-sync discrepancies between `bom/BOM.md` and root `BOM.md`.
