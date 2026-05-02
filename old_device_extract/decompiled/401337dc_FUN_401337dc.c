// Function : FUN_401337dc
// Address  : 0x401337dc
// Size     : 501 bytes


int FUN_401337dc(int param_1,byte *param_2,uint param_3,undefined4 param_4,uint param_5,int *param_6
                )

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  
  uVar5 = param_3 - 0xb;
  iVar6 = (uVar5 < param_5) * uVar5 + (uVar5 >= param_5) * param_5;
  if (param_1 == 1) {
    uVar5 = (uint)*param_2 | param_2[1] ^ 2;
    uVar7 = 0;
    iVar3 = 0;
    for (uVar8 = 2; uVar8 < param_3; uVar8 = uVar8 + 1) {
      uVar7 = uVar7 | ((uint)param_2[uVar8] | -(uint)param_2[uVar8]) >> 7 & 1 ^ 1;
      iVar3 = iVar3 + (-uVar7 >> 7 & 1 ^ 1);
    }
  }
  else {
    uVar5 = (uint)*param_2 | param_2[1] ^ 1;
    uVar7 = 0;
    iVar3 = 0;
    for (uVar8 = 2; uVar8 < param_3; uVar8 = uVar8 + 1) {
      uVar7 = uVar7 | -(uint)param_2[uVar8] >> 0x1f ^ 1;
      iVar3 = iVar3 + (-uVar7 >> 0x1f ^ 1);
      memw();
      uVar4 = FUN_40186390(uVar7,0,(param_2[uVar8] ^ 0xffffffff) & 0xff);
      uVar5 = uVar5 | uVar4;
    }
  }
  uVar4 = -uVar7 >> 0x1f ^ 1 | iVar3 - 8U >> 0x1f | uVar5;
  memw();
  iVar3 = FUN_40186390(uVar4,iVar6,(param_3 - 3) - iVar3);
  uVar8 = iVar6 - iVar3 >> 0x1f;
  uVar7 = -uVar8;
  iVar2 = FUN_40186390(uVar4,0x4100,uVar8 & 0x4400);
  uVar8 = 0xb;
  while (uVar8 < param_3) {
    pbVar9 = param_2 + uVar8;
    uVar8 = uVar8 + 1;
    *pbVar9 = ((char)((byte)(-(uVar4 | uVar7) >> 0x18) | (byte)(uVar5 >> 0x18)) >> 7 ^ 0xffU) &
              *pbVar9;
    memw();
    memw();
  }
  memw();
  iVar3 = FUN_40186390(uVar7,iVar6,iVar3);
  param_2 = param_2 + (param_3 - iVar6);
  if (iVar6 != 0) {
    uVar5 = -iVar3;
    do {
      uVar7 = uVar5 >> 0x1f;
      uVar8 = 0;
      while (uVar8 < iVar6 - 1U) {
        pbVar9 = param_2 + uVar8;
        uVar8 = uVar8 + 1;
        memw();
        memw();
        memw();
        bVar1 = FUN_40186390(uVar7,*pbVar9,param_2[uVar8]);
        memw();
        *pbVar9 = bVar1;
        memw();
      }
      uVar5 = uVar5 + 1;
      memw();
      memw();
      bVar1 = FUN_40186390(uVar7,param_2[iVar6 - 1U],0);
      memw();
      param_2[iVar6 - 1U] = bVar1;
    } while (iVar6 - iVar3 != uVar5);
    memw();
  }
  if (param_5 != 0) {
    (*(code *)&SUB_4008b3d0)(param_4,param_2,iVar6);
  }
  *param_6 = iVar3;
  memw();
  return -iVar2;
}

