// Function : FUN_4018e41c
// Address  : 0x4018e41c
// Size     : 83 bytes


void FUN_4018e41c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  while (param_1 < 0xf) {
    iVar2 = param_1 * 2 + 1;
    iVar1 = param_1 * 2 + 2;
    if (*(uint *)(&DAT_3ffc65c4 + iVar1 * 8) >> 3 <= *(uint *)(&DAT_3ffc65c4 + iVar2 * 8) >> 3) {
      iVar2 = iVar1;
    }
    iVar1 = iVar2 * 8;
    param_1 = param_1 * 8;
    uVar5 = *(undefined4 *)(&DAT_3ffc65c4 + iVar1);
    uVar4 = *(undefined4 *)(&DAT_3ffc65c0 + param_1);
    uVar3 = *(undefined4 *)(&DAT_3ffc65c4 + param_1);
    *(undefined4 *)(&DAT_3ffc65c0 + param_1) = *(undefined4 *)(&DAT_3ffc65c0 + iVar1);
    *(undefined4 *)(&DAT_3ffc65c4 + param_1) = uVar5;
    *(undefined4 *)(&DAT_3ffc65c0 + iVar1) = uVar4;
    *(undefined4 *)(&DAT_3ffc65c4 + iVar1) = uVar3;
    memw();
    param_1 = iVar2;
  }
  return;
}

