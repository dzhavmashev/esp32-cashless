// Function : FUN_4017f3b8
// Address  : 0x4017f3b8
// Size     : 111 bytes


uint FUN_4017f3b8(undefined4 param_1,int param_2,uint param_3,uint param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_4 * param_3;
  uVar5 = 0;
  uVar1 = uVar4;
  if (uVar4 != 0) {
    do {
      uVar5 = uVar1;
      uVar3 = param_5[1];
      if (uVar5 <= uVar3) {
        (*(code *)&SUB_4008b3d0)(param_2,*param_5,uVar5);
        *param_5 = *param_5 + uVar5;
        param_5[1] = param_5[1] - uVar5;
        return param_4;
      }
      (*(code *)&SUB_4008b3d0)(param_2,*param_5,uVar3);
      *param_5 = *param_5 + uVar3;
      param_5[1] = 0;
      iVar2 = FUN_4017f378(param_1,param_5);
      param_2 = param_2 + uVar3;
      uVar1 = uVar5 - uVar3;
    } while (iVar2 == 0);
    uVar5 = ((uVar3 + uVar4) - uVar5) / param_3;
  }
  return uVar5;
}

