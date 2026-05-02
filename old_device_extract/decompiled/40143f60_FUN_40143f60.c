// Function : FUN_40143f60
// Address  : 0x40143f60
// Size     : 132 bytes


int FUN_40143f60(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_28;
  int *piStack_24;
  
  iVar1 = FUN_40186520(param_2);
  if ((iVar1 == 1) || (iVar1 == 6)) {
    uVar2 = FUN_40186508(param_2);
    iVar1 = -(uint)(uVar2 < *(uint *)(param_1 + 0xc));
  }
  else {
    if (iVar1 - 2U < 3) {
      uStack_28 = *param_2;
      piStack_24 = (int *)param_2[1];
      memw();
      iVar1 = FUN_40186520(&uStack_28);
      if (2 < iVar1 - 2U) {
        memw();
        breakpoint(0x1000,0x40143fe2,1,0xf);
        do {
          ill();
        } while( true );
      }
      if (*piStack_24 != 0) {
        return -(uint)((1 << 0x20 - (0x20 - (*piStack_24 - 1U & 0x1f)) & *(uint *)(param_1 + 8)) ==
                      0);
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}

