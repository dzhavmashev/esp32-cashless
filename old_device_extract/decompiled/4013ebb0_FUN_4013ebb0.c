// Function : FUN_4013ebb0
// Address  : 0x4013ebb0
// Size     : 140 bytes


int FUN_4013ebb0(uint *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_1 & 0x3f;
  uVar2 = *param_1 + param_3;
  uVar4 = 0x40 - uVar3;
  *param_1 = uVar2;
  if (uVar2 < param_3) {
    param_1[1] = param_1[1] + 1;
  }
  if ((uVar3 != 0) && (uVar4 <= param_3)) {
    memw();
    (*(code *)&SUB_4008b3d0)((int)(param_1 + 7) + uVar3,param_2,uVar4);
    iVar1 = FUN_4013d9ec(param_1,param_1 + 7,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_3 = uVar3 + (param_3 - 0x40);
    param_2 = param_2 + uVar4;
    uVar3 = 0;
  }
  param_2 = param_2 + param_3;
  while( true ) {
    iVar1 = param_2 - param_3;
    if (param_3 < 0x40) {
      if (param_1[0x17] == 1) {
        FUN_401436b0(0,param_1 + 2);
      }
      if (param_3 != 0) {
        (*(code *)&SUB_4008b3d0)((int)param_1 + uVar3 + 0x1c,iVar1,param_3);
      }
      return 0;
    }
    iVar1 = FUN_4013d9ec(param_1,iVar1,0);
    if (iVar1 != 0) break;
    param_3 = param_3 - 0x40;
  }
  return iVar1;
}

