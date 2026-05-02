// Function : FUN_401284e0
// Address  : 0x401284e0
// Size     : 162 bytes


int FUN_401284e0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = -1;
  if (*(int *)(param_1 + 0x48) != 0) {
    uVar1 = FUN_40185088(param_2,0);
    FUN_40125ffc(param_2,*(undefined2 *)(param_1 + 4));
    if (*(short *)(param_1 + 4) != -1) {
      *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
      memw();
    }
    iVar6 = *(int *)(param_1 + 0x48);
    uVar4 = *(undefined4 *)(iVar6 + 0x20);
    uVar5 = *(undefined4 *)(param_1 + 0x38);
    if (*(int *)(iVar6 + 0x40) == 0) {
      uVar3 = *(undefined4 *)(iVar6 + 0x24);
      uVar7 = *(undefined4 *)(iVar6 + 0x2c);
      memw();
      uVar2 = FUN_40185088(param_2,0x20);
      memw();
      iVar6 = FUN_401260fc(param_1,uVar1,uVar4,uVar3,uVar5,uVar7,uVar2);
    }
    else {
      uVar7 = *(undefined4 *)(iVar6 + 0x30);
      uVar3 = *(undefined4 *)(iVar6 + 0x28);
      memw();
      uVar2 = FUN_40185088(param_2,0x20);
      memw();
      iVar6 = FUN_40126194(param_1,uVar1,uVar4,uVar3,uVar5,uVar7,uVar2);
    }
    iVar6 = -(uint)(iVar6 != 0);
  }
  return iVar6;
}

