// Function : FUN_401603f4
// Address  : 0x401603f4
// Size     : 197 bytes


void FUN_401603f4(int param_1,int param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  
  if (param_2 == 0) goto LAB_40160475;
  do {
    iVar3 = *(int *)(param_2 + 0x2c);
    uVar2 = *(uint *)(iVar3 + 4) >> 4 & 0xf;
    if (uVar2 < 5) {
      iVar1 = uVar2 + 0xe;
      if (*(byte *)(iVar3 + 6) < DAT_3ffbfff5) {
        if (*(byte *)(iVar3 + 7) < DAT_3ffbfff4) {
          iVar3 = FUN_40187d04(param_2);
          iVar1 = iVar1 * 8;
          if (iVar3 == 0) {
            *(char *)(iVar1 + 0x3ffc7c67) = *(char *)(iVar1 + 0x3ffc7c67) + '\x01';
            memw();
          }
          else {
            *(char *)(iVar1 + 0x3ffc7c66) = *(char *)(iVar1 + 0x3ffc7c66) + '\x01';
            memw();
            memw();
          }
        }
        else {
          *(char *)(iVar1 * 8 + 0x3ffc7c64) = *(char *)(iVar1 * 8 + 0x3ffc7c64) + '\x01';
          memw();
          memw();
        }
      }
      else {
        *(char *)(iVar1 * 8 + 0x3ffc7c65) = *(char *)(iVar1 * 8 + 0x3ffc7c65) + '\x01';
        memw();
        memw();
      }
    }
LAB_40160475:
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    *(undefined1 *)(*(int *)(param_2 + 0x2c) + 0x13) = param_3;
    memw();
    uVar4 = 0;
    if ((**(uint **)(param_2 + 0x2c) & 0xc0) != 0x80) {
      uVar4 = param_4;
    }
    memw();
    FUN_40187fa0(param_2,uVar4);
  } while (((**(uint **)(param_2 + 0x2c) & 0xc0) == 0x80) &&
          (param_2 = FUN_40162d70((*(uint **)(param_2 + 0x2c))[4] >> 0x14 & 0xf), param_2 != 0));
  return;
}

