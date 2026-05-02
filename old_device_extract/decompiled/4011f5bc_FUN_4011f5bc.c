// Function : FUN_4011f5bc
// Address  : 0x4011f5bc
// Size     : 115 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011f5bc(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_t0;
  
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(0x3ffbdc68,0xffffffff);
  iVar2 = _DAT_3ffc6728 + -1;
  _DAT_3ffc6728 = iVar2;
  if (iVar2 < 0) {
    memw();
    (*(code *)&SUB_40092bec)(0x3ffbdc68);
    uVar1 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"_timing","ph_ctrl",uVar1,"_timing","t == 0\n");
    iVar2 = in_t0;
    (*(code *)&SUB_40094bc8)();
  }
  if (iVar2 == 0) {
    memw();
    _DAT_3ff4880c = _DAT_3ff4880c & 0xfff3ffff;
    memw();
  }
  memw();
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(0x3ffbdc68);
  return;
}

