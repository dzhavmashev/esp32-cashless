// Function : FUN_4015469c
// Address  : 0x4015469c
// Size     : 138 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015469c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"memory!",&UNK_3f423e3d,0xa8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_40154598(param_1,param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 == 4) {
    FUN_40160074(_DAT_3ffc8804 == param_1,6);
  }
  else {
    FUN_40160074(_DAT_3ffc8804 == param_1);
    if (param_2 - 2U < 2) {
      uVar2 = *(uint *)(param_1 + 0xa4) | 0x2000;
      goto LAB_40154706;
    }
  }
  uVar2 = *(uint *)(param_1 + 0xa4) & 0xffffdfff;
LAB_40154706:
  *(uint *)(param_1 + 0xa4) = uVar2;
  if (*(char *)(_DAT_3ffbfc54 + 1) == '\0') {
    FUN_40165d18();
    FUN_40147358();
    return 0;
  }
  memw();
  FUN_40165d20();
  FUN_401472a8();
  return 0;
}

