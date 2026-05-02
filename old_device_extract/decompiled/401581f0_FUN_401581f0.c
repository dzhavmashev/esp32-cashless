// Function : FUN_401581f0
// Address  : 0x401581f0
// Size     : 360 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401581f0(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(*(int *)(param_3 + 4) + 4);
  if ((*(int *)(_DAT_3ffca40c + 4) == 0) || (*(int *)(_DAT_3ffca40c + 8) != 2)) {
    sVar1 = *(short *)(iVar2 + 0xc);
    if ((sVar1 != -0x4b78) && (sVar1 != -0x7178)) {
      if ((*(uint *)(*(int *)(param_1 + 0xe4) + 0xc) & 1) == 0) {
        return 1;
      }
      return 2;
    }
    if (((*(uint *)(*(int *)(param_1 + 0xe4) + 0xc) & 1) == 0) &&
       (1 < (byte)(*(char *)(param_2 + 0x24) - 1U))) {
      return 1;
    }
    if ((DAT_3ffc89ed < 0xe) && ((0x2410U >> (DAT_3ffc89ed & 0x1f) & 1) == 1)) {
      if (_DAT_3ffc89a8 == (undefined4 *)0x0) {
        return 1;
      }
      if ((code *)*_DAT_3ffc89a8 == (code *)0x0) {
        return 1;
      }
      (*(code *)*_DAT_3ffc89a8)(iVar2 + 6,iVar2 + 0xe,*(ushort *)(param_3 + 0x16) - 0xe,param_2 + 4)
      ;
      if (_DAT_3ffc8a30 != 2) {
        if (_DAT_3ffc8a30 != 3) {
          return 1;
        }
        if (_DAT_3ffc89a8 == (undefined4 *)0x0) {
          return 1;
        }
        if ((code *)_DAT_3ffc89a8[4] == (code *)0x0) {
          return 1;
        }
        (*(code *)_DAT_3ffc89a8[4])();
        return 1;
      }
      if (_DAT_3ffc89a4 == 0) {
        return 1;
      }
      if (*(code **)(_DAT_3ffc89a4 + 0x40) == (code *)0x0) {
        return 1;
      }
      (**(code **)(_DAT_3ffc89a4 + 0x40))(param_2 + 4);
      return 1;
    }
    if (*(char *)(param_2 + 0x24) == '\x02') {
      if (sVar1 != -0x4b78) {
        return 1;
      }
      if (_DAT_3ffc8a64 == (undefined4 *)0x0) {
        return 1;
      }
      if ((code *)*_DAT_3ffc8a64 == (code *)0x0) {
        return 1;
      }
      (*(code *)*_DAT_3ffc8a64)(iVar2 + 6,iVar2 + 0xe,*(ushort *)(param_3 + 0x16) - 0xe);
      return 1;
    }
    memw();
    FUN_40147fe4(1,0x24,5,0x3f4361e4);
    if (((DAT_3ffc89ed < 0xe) && ((1 << (DAT_3ffc89ed & 0x1f) & 0x2410U) != 0)) &&
       (_DAT_3ffc8a30 != 2)) {
      return 1;
    }
    if (_DAT_3ffc89a4 == 0) {
      return 1;
    }
    iVar2 = (**(code **)(_DAT_3ffc89a4 + 0x14))
                      (iVar2 + 6,*(int *)(*(int *)(param_3 + 4) + 4) + 0xe,
                       *(ushort *)(param_3 + 0x16) - 0xe);
    uVar4 = 0x3f4361d0;
    if (iVar2 != 0) {
      uVar4 = 0x3f4361b9;
    }
    uVar3 = 5;
  }
  else {
    if (_DAT_3ffc89ac == 0) {
      return 1;
    }
    if (*(code **)(_DAT_3ffc89ac + 8) == (code *)0x0) {
      return 1;
    }
    iVar2 = (**(code **)(_DAT_3ffc89ac + 8))
                      (iVar2 + 6,iVar2 + 0xe,*(ushort *)(param_3 + 0x16) - 0xe);
    uVar4 = 0x3f433e4c;
    if (iVar2 != 0) {
      uVar4 = 0x3f433e36;
    }
    uVar3 = 4;
  }
  FUN_40147fe4(1,0x24,uVar3,uVar4);
  return 1;
}

