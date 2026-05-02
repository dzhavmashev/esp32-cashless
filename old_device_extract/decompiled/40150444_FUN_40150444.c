// Function : FUN_40150444
// Address  : 0x40150444
// Size     : 376 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40150444(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0x102;
  if (param_1 == (byte *)0x0) {
    return 0x102;
  }
  if (*param_1 < 0x5c) {
    param_1[1] = 0;
    memw();
    memw();
    iVar2 = FUN_4014dd48();
    if (iVar2 == 0) {
      param_1[1] = param_1[1] | 1;
      memw();
    }
    if ((*param_1 != 0x31) || (param_1[8] != 2)) {
      param_1[1] = param_1[1] | 2;
      memw();
    }
    if ((param_1[1] & 3) == 3) {
      memw();
      iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x44))();
      *(int *)(param_1 + 0x10) = iVar2;
      if (iVar2 == 0) {
        memw();
        (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
        FUN_40147fe4(1,2,2,0x3f4367a8);
        return 0x101;
      }
    }
    bVar1 = param_1[1];
    if ((bVar1 & 1) == 0) {
      iVar2 = FUN_4014d828(param_1);
      if ((bVar1 & 2) == 0) {
        return 0;
      }
    }
    else {
      iVar2 = FUN_4014605c();
      if (iVar2 == 0) {
        iVar3 = FUN_40146034();
        if (((iVar3 != 3) && (*param_1 != 0)) && (*param_1 != 0x26)) {
          FUN_401460a4();
          (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
          return 0x3001;
        }
        iVar3 = FUN_40146044();
        if (((iVar3 != 0) && (*param_1 != 2)) && (*param_1 != 0x1a)) {
          FUN_401460a4();
          (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
          return 0x3014;
        }
        iVar3 = (*(code *)&SUB_40087bcc)(6,param_1);
        if (iVar3 != 0) {
          FUN_40147fe4(1,2,2,0x3f436785,*param_1);
          FUN_401460a4();
          (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
          return 0x3012;
        }
        FUN_401460a4();
        if ((bVar1 & 2) == 0) {
          return 0;
        }
        iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x3c))(*(undefined4 *)(param_1 + 0x10),0xffffffff);
        if (iVar3 == 1) {
          iVar2 = *(int *)(param_1 + 0xc);
        }
      }
    }
  }
  (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
  return iVar2;
}

