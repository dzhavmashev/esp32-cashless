// Function : FUN_401080a8
// Address  : 0x401080a8
// Size     : 233 bytes


char FUN_401080a8(undefined4 *param_1,uint param_2,int *param_3,ushort *param_4)

{
  ushort uVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *local_24 [9];
  
  if ((param_3[2] == 0) && (0 < param_3[3])) {
    cVar3 = -0x10;
  }
  else {
    uVar4 = 0;
    if ((param_2 & 8) != 0) {
      uVar4 = 4;
    }
    local_24[0] = (int *)param_1[1];
    if (local_24[0] == (int *)0x0) {
      memw();
      cVar3 = FUN_4011c4a8(*param_1,local_24,uVar4);
      piVar2 = local_24[0];
      if (cVar3 != '\0') {
        return cVar3;
      }
      if (local_24[0] == (int *)0x0) {
        (*(code *)&SUB_40094c54)("!= NULL",0x49a,"allback","sed > 0");
      }
      param_1[1] = piVar2;
    }
    iVar7 = 0;
    uVar1 = *(ushort *)(*local_24[0] + 8);
    for (uVar6 = 0; (iVar7 < param_3[3] && (uVar6 < uVar1)); uVar6 = uVar6 + uVar5 & 0xffff) {
      puVar8 = (undefined4 *)(param_3[2] + iVar7 * 8);
      uVar5 = uVar1 - uVar6 & 0xffff;
      uVar9 = puVar8[1];
      if (uVar9 <= uVar5) {
        uVar5 = uVar9 & 0xffff;
      }
      memw();
      FUN_4010bfb8(*local_24[0],*puVar8,uVar5,uVar6);
      iVar7 = iVar7 + 1;
    }
    if ((*param_3 != 0) && (param_3[1] != 0)) {
      memw();
      FUN_401078c8(*param_1,local_24[0] + 2,(short)local_24[0][8],*param_3,param_3 + 1);
    }
    param_3[6] = 0;
    if (param_3[4] != 0) {
      param_3[5] = 0;
    }
    if ((param_2 & 1) == 0) {
      param_1[1] = 0;
      memw();
      FUN_4011da08(local_24[0]);
    }
    cVar3 = '\0';
    *param_4 = uVar1;
    memw();
    memw();
  }
  return cVar3;
}

