// Function : FUN_4014d67c
// Address  : 0x4014d67c
// Size     : 134 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014d67c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_40 [12];
  int iStack_34;
  
  iVar3 = *(int *)(param_1 + 0x38);
  if ((iVar3 != 0) && (0x13 < *(byte *)(iVar3 + 1))) {
    if ((_DAT_3ffc8a64 == 0) || (*(code **)(_DAT_3ffc8a64 + 4) == (code *)0x0)) {
      FUN_40147fe4(1,0x80,2,0x3f4366c6);
    }
    else {
      uVar1 = *(byte *)(iVar3 + 1) + 2;
      iVar3 = (**(code **)(_DAT_3ffc8a64 + 4))(iVar3,uVar1 & 0xff,auStack_40);
      if (iVar3 == 0) {
        if ((_DAT_3ffc8a64 != 0) && (*(code **)(_DAT_3ffc8a64 + 0xc) != (code *)0x0)) {
          (**(code **)(_DAT_3ffc8a64 + 0xc))(*(undefined4 *)(param_1 + 0x38),uVar1);
        }
        DAT_3ffc89f0 = 10;
        DAT_3ffc89ee = 10;
        memw();
        DAT_3ffc89ec = 7;
        memw();
        uVar2 = 1;
        if (iStack_34 == 0x1000) {
          DAT_3ffc89ed = 0xb;
          *(undefined1 *)(param_1 + 0x7c) = 8;
          memw();
        }
        goto LAB_4014d701;
      }
    }
  }
  uVar2 = 0;
LAB_4014d701:
  memw();
  return uVar2;
}

