// Function : FUN_4011519c
// Address  : 0x4011519c
// Size     : 314 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011519c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  char cStack_24;
  
  iVar4 = *(int *)(param_1 + 200);
  if ((iVar4 != 0) && (*(char *)(iVar4 + 5) != '\0')) {
    cStack_24 = *(char *)(iVar4 + 0x38);
    uStack_38 = *(undefined4 *)(iVar4 + 0x24);
    memw();
    if (cStack_24 == '\x06') {
      uStack_34 = *(undefined4 *)(iVar4 + 0x28);
      uStack_30 = *(undefined4 *)(iVar4 + 0x2c);
      uStack_2c = *(undefined4 *)(iVar4 + 0x30);
      uStack_28 = *(undefined1 *)(iVar4 + 0x34);
    }
    else {
      uStack_28 = 0;
      uStack_2c = 0;
      uStack_30 = 0;
      uStack_34 = 0;
      memw();
    }
    *(undefined4 *)(iVar4 + 0x24) = 0;
    *(undefined4 *)(iVar4 + 0x28) = 0;
    *(undefined4 *)(iVar4 + 0x2c) = 0;
    *(undefined4 *)(iVar4 + 0x30) = 0;
    *(undefined1 *)(iVar4 + 0x34) = 0;
    *(undefined1 *)(iVar4 + 0x38) = 0;
    *(undefined4 *)(iVar4 + 0x3c) = 0;
    *(undefined4 *)(iVar4 + 0x40) = 0;
    *(undefined4 *)(iVar4 + 0x44) = 0;
    *(undefined4 *)(iVar4 + 0x50) = 0;
    *(undefined4 *)(iVar4 + 0x4c) = 0;
    *(undefined4 *)(iVar4 + 0x48) = 0;
    *(undefined4 *)(iVar4 + 0x20) = 0;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    *(undefined4 *)(iVar4 + 0x18) = 0;
    *(undefined4 *)(iVar4 + 0x14) = 0;
    memw();
    memw();
    iVar1 = FUN_40185450(param_1);
    if (iVar1 != 0) {
      iVar1 = FUN_40114430(param_1,iVar4,7,&uStack_3a);
      if (iVar1 != 0) {
        iVar6 = *(int *)(iVar1 + 4);
        iVar5 = iVar6 + 0xf0;
        uVar2 = FUN_401142d4(uStack_3a,iVar5,0x36,4);
        uStack_3a = (undefined2)uVar2;
        memw();
        memw();
        uVar3 = FUN_40109eec(uStack_38);
        uVar2 = FUN_40114328(uVar2,iVar5,uVar3);
        uStack_3a = (undefined2)uVar2;
        memw();
        memw();
        uVar2 = FUN_401145e4(param_1,iVar6,uVar2);
        uStack_3a = (undefined2)uVar2;
        memw();
        memw();
        FUN_40114068(uVar2,iVar5,iVar1);
        FUN_40113b68(_DAT_3ffc6380,iVar1,&uStack_38,0x43,param_1);
        FUN_4010bb10(iVar1);
      }
      FUN_4010b270(param_1,&DAT_3f411ef4,&DAT_3f411ef4,&DAT_3f411ef4);
      if (*(code **)(iVar4 + 0x54) != (code *)0x0) {
        (**(code **)(iVar4 + 0x54))(param_1);
      }
    }
    if (*(char *)(iVar4 + 8) != '\0') {
      FUN_40113304(&DAT_40115654,param_1);
      *(undefined1 *)(iVar4 + 8) = 0;
      memw();
    }
    memw();
    FUN_4018541c(iVar4,0);
    if (*(char *)(iVar4 + 4) != '\0') {
      FUN_4011437c();
      *(undefined1 *)(iVar4 + 4) = 0;
      memw();
    }
  }
  memw();
  return;
}

