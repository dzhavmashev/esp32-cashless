// Function : FUN_40153144
// Address  : 0x40153144
// Size     : 96 bytes


bool FUN_40153144(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_30 [48];
  
  uVar3 = *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1;
  if (uVar3 == (*(uint *)(*(int *)(param_2 + 0x2c) + 0x10) >> 0x13 & 1)) {
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 4) + 4);
    uVar4 = *(undefined4 *)(*(int *)(param_2 + 4) + 4);
    iVar1 = FUN_40152e4c(uVar3,uVar4,auStack_30);
    if ((iVar1 != 0) &&
       ((uVar3 != 1 || (iVar2 = (*(code *)&SUB_4008b33c)(uVar5,uVar4,6), iVar2 == 0)))) {
      uVar3 = FUN_40151f00(iVar1,param_2);
      return (*(uint *)(*(int *)(param_1 + 0x2c) + 4) & 0xf) == uVar3;
    }
  }
  return false;
}

