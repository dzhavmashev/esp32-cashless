// Function : FUN_4015436c
// Address  : 0x4015436c
// Size     : 257 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015436c(char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 auStack_30 [12];
  
  auStack_30[0] = 0;
  if ((_DAT_3ffc8800 == 0) || (iVar2 = *(int *)(_DAT_3ffc8800 + 0xe4), iVar2 == 0)) {
    uVar5 = 0x3f436a50;
    if (_DAT_3ffc8864 == 0) {
LAB_401543ad:
      FUN_40147fe4(1,0x40,2,uVar5);
      return;
    }
    memw();
  }
  else {
    iVar1 = FUN_4015f5c0(auStack_30,0x18,0);
    if (iVar1 == 0) {
      uVar5 = 0x3f436a46;
      goto LAB_401543ad;
    }
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 4);
    (*(code *)&SUB_4008b530)(iVar3,0,0x18);
    puVar4 = *(uint **)(iVar1 + 4);
    *(undefined2 *)(iVar1 + 0x14) = 0x18;
    *(undefined2 *)(iVar1 + 0x16) = 0;
    memw();
    memw();
    memw();
    *puVar4 = *puVar4 | 0x80000000;
    memw();
    memw();
    *puVar4 = *puVar4 | 0x40000000;
    memw();
    memw();
    *puVar4 = *puVar4 & 0xdfffffff;
    memw();
    memw();
    *puVar4 = *puVar4 & 0xff000fff | 0x18000;
    memw();
    uVar5 = FUN_4015f9bc(0);
    memw();
    FUN_40151c80(iVar2,iVar1,0x48,0x10,uVar5,iVar2 + 4,iVar2 + 4);
    FUN_40153a2c(iVar2,iVar1,7,8,0);
    if (param_1 == '\0') {
      iVar2 = *(int *)(iVar1 + 0x2c);
      uVar5 = 0x40;
    }
    else {
      uVar5 = 0x20;
      *(byte *)(iVar3 + 1) = *(byte *)(iVar3 + 1) | 0x10;
      memw();
      iVar2 = *(int *)(iVar1 + 0x2c);
      memw();
    }
    *(undefined4 *)(iVar2 + 0x14) = uVar5;
  }
  memw();
  return;
}

