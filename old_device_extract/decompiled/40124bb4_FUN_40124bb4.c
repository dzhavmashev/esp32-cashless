// Function : FUN_40124bb4
// Address  : 0x40124bb4
// Size     : 179 bytes


void FUN_40124bb4(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 != 0) {
    uVar2 = param_3 & 8;
    memw();
    FUN_4012481c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,0);
    uVar3 = 1000;
    iVar1 = *(int *)(param_2 + 0x30);
    if (uVar2 != 0) {
      iVar1 = *(int *)(param_2 + 0x2c);
    }
    if (((iVar1 == 1) && (*(int *)(param_1 + 0x40) != 0)) && (uVar3 = 500, uVar2 != 0)) {
      uVar3 = 100;
    }
    if (((uVar2 != 0) && (iVar1 == 1)) && ((param_3 & 0x100) == 0)) {
      *(undefined4 *)(param_2 + 0x1c0) = 1;
    }
    iVar1 = param_2 + 0x1c8;
    memw();
    FUN_401850a4(uVar3 / 1000,(uVar3 % 1000) * 1000,0x40125468,param_1,param_2);
    (*(code *)&SUB_40085b60)(iVar1);
    FUN_4011f9a4(iVar1,0x40124414,*(undefined4 *)(param_2 + 0x1c4));
    (*(code *)&SUB_40085b00)(iVar1,1000,0);
  }
  return;
}

