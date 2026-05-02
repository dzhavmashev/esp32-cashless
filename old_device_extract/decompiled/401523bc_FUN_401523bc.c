// Function : FUN_401523bc
// Address  : 0x401523bc
// Size     : 138 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_401523bc(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_1 != (int *)0x0) && (iVar4 = *param_1, iVar4 != 0)) {
    if (*(int *)(iVar4 + 0x14c) == 0) {
      uVar2 = 0x11;
      if (DAT_3ffc89ee == '\0') {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
      if ((*(int *)(iVar4 + 0x14c) == 1) && (uVar2 = 0x11, (*(uint *)(iVar4 + 0xa4) >> 4 & 1) == 0))
      {
        uVar2 = 1;
      }
    }
    uVar3 = 0x20;
    if (_DAT_3ffc8804 == iVar4 || (*(ushort *)((int)param_1 + 0x2a) & 0x400) != 0) {
      uVar3 = 0x420;
    }
    uVar1 = uVar2 | uVar3;
    if (*(char *)(_DAT_3ffbfc54 + 0x362) != '\0') {
      uVar1 = uVar2 | uVar3 | 0x1000;
    }
    return uVar1;
  }
  FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0xb21);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

