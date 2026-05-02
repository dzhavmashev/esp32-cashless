// Function : FUN_400f8758
// Address  : 0x400f8758
// Size     : 89 bytes


int FUN_400f8758(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(char *)((int)param_1 + 0x1b) != '\0') {
    iVar1 = FUN_400f8574(*param_1 + param_1[0x37],param_1 + 0x38,0x20,1);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_1[0x37] = param_1[0x37] + 0x20;
  }
  iVar1 = 0;
  uVar2 = param_1[0x37];
  if ((param_2 < uVar2) && (iVar1 = 0x2002, param_3 == 0)) {
    memw();
    uVar3 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"_common","max %d\n",uVar3,"_common",uVar2,param_2);
    iVar1 = 0x2002;
  }
  return iVar1;
}

