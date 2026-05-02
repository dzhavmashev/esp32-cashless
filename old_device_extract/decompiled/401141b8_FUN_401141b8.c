// Function : FUN_401141b8
// Address  : 0x401141b8
// Size     : 219 bytes


void FUN_401141b8(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uStack_28;
  uint auStack_24 [9];
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 200), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    iVar2 = *(int *)(iVar1 + 0x48);
    if (iVar2 != -1) {
      if (iVar2 == 0) {
        iVar2 = 0x78;
      }
      *(int *)(iVar1 + 0x20) = iVar2;
    }
    uVar3 = *(uint *)(iVar1 + 0x4c);
    if (uVar3 != 0xffffffff) {
      if (uVar3 == 0) {
        uVar3 = *(uint *)(iVar1 + 0x20) >> 1;
      }
      *(uint *)(iVar1 + 0xc) = uVar3;
      *(uint *)(iVar1 + 0x14) = uVar3;
    }
    iVar2 = *(int *)(iVar1 + 0x50);
    if (iVar2 != -1) {
      if (iVar2 == 0) {
        iVar2 = (*(uint *)(iVar1 + 0x20) >> 3) * 7;
      }
      *(int *)(iVar1 + 0x10) = iVar2;
      *(int *)(iVar1 + 0x18) = iVar2;
    }
    if ((*(uint *)(iVar1 + 0x10) <= *(uint *)(iVar1 + 0xc)) && (*(uint *)(iVar1 + 0x10) != 0)) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    if (*(char *)(iVar1 + 7) == '\0') {
      if ((char)*(byte *)(iVar1 + 0x3c) < '\0') {
        if (*(byte *)(iVar1 + 0x3c) < 0xc0) {
          uStack_28 = 0xffff;
        }
        else {
          uStack_28 = 0xffffff;
        }
      }
      else {
        uStack_28 = 0xff;
      }
    }
    else {
      uStack_28 = *(uint *)(iVar1 + 0x40);
    }
    auStack_24[0] = *(uint *)(iVar1 + 0x44);
    if (auStack_24[0] == 0) {
      auStack_24[0] = *(uint *)(iVar1 + 0x3c) & uStack_28 | 0x1000000;
    }
    memw();
    FUN_4018541c(iVar1,10);
    if (*(char *)(iVar1 + 8) != '\0') {
      FUN_40113304(&DAT_40115654,param_1);
      *(undefined1 *)(iVar1 + 8) = 0;
      memw();
    }
    memw();
    FUN_4010b270(param_1,iVar1 + 0x3c,&uStack_28,auStack_24);
    FUN_4011b184(param_1);
    if (*(code **)(iVar1 + 0x54) != (code *)0x0) {
      (**(code **)(iVar1 + 0x54))(param_1);
    }
  }
  return;
}

