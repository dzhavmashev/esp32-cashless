// Function : FUN_401408cc
// Address  : 0x401408cc
// Size     : 190 bytes


int FUN_401408cc(uint *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *param_1;
  uVar3 = uVar6 & 0x7f;
  uVar5 = uVar6 + param_3;
  uVar4 = 0x80 - uVar3;
  uVar6 = (uint)(uVar5 < uVar6) + param_1[1];
  *param_1 = uVar5;
  param_1[1] = uVar6;
  if ((uVar6 == 0) && (uVar5 < param_3)) {
    uVar5 = param_1[2];
    uVar6 = uVar5 + 1;
    param_1[2] = uVar6;
    param_1[3] = (uint)(uVar6 < uVar5) + param_1[3];
  }
  if ((uVar3 != 0) && (uVar4 <= param_3)) {
    memw();
    (*(code *)&SUB_4008b3d0)((int)(param_1 + 0x14) + uVar3,param_2,uVar4);
    iVar1 = FUN_4014086c(param_1,param_1 + 0x14,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_3 = uVar3 + (param_3 - 0x80);
    param_2 = param_2 + uVar4;
    uVar3 = 0;
  }
  param_2 = param_2 + param_3;
  while( true ) {
    iVar1 = param_2 - param_3;
    if (param_3 < 0x80) {
      if (param_1[0x35] == 1) {
        uVar2 = 3;
        if (param_1[0x34] != 0) {
          uVar2 = 2;
        }
        FUN_401436b0(uVar2,param_1 + 4);
      }
      if (param_3 != 0) {
        (*(code *)&SUB_4008b3d0)((int)param_1 + uVar3 + 0x50,iVar1,param_3);
      }
      return 0;
    }
    iVar1 = FUN_4014086c(param_1,iVar1,0);
    if (iVar1 != 0) break;
    param_3 = param_3 - 0x80;
  }
  return iVar1;
}

