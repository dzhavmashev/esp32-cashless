// Function : FUN_401214fc
// Address  : 0x401214fc
// Size     : 203 bytes


undefined4
FUN_401214fc(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,
            uint *param_6)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = FUN_401214a0(param_2,param_1);
  uVar3 = 0xffffffff;
  if (param_4 != 0x20) {
    uVar3 = (1 << 0x20 - (0x20 - (param_4 & 0x1f))) - 1;
  }
  uVar3 = uVar2 >> (param_3 & 0x1f) & uVar3;
  uVar7 = *param_6;
  uVar2 = uVar7 & 0x80000007;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  iVar4 = 0;
  if (uVar2 != 0) {
    uVar5 = uVar7 + 7;
    if (-1 < (int)uVar7) {
      uVar5 = uVar7;
    }
    pbVar6 = (byte *)(param_5 + ((int)uVar5 >> 3));
    memw();
    bVar1 = (*(code *)&SUB_4000c818)(uVar3,0,uVar2);
    *pbVar6 = bVar1 | *pbVar6;
    memw();
    iVar4 = 8 - uVar2;
    iVar4 = (uint)(iVar4 < (int)param_4) * iVar4 + (iVar4 >= (int)param_4) * param_4;
    param_4 = param_4 - iVar4;
    *param_6 = uVar7 + iVar4;
  }
  iVar8 = 0;
  while (0 < (int)param_4) {
    uVar7 = *param_6;
    iVar8 = iVar8 + iVar4;
    uVar2 = uVar7 + 7;
    if (-1 < (int)uVar7) {
      uVar2 = uVar7;
    }
    pbVar6 = (byte *)(param_5 + ((int)uVar2 >> 3));
    memw();
    bVar1 = (*(code *)&SUB_4000c84c)(uVar3,0,iVar8);
    *pbVar6 = bVar1 | *pbVar6;
    memw();
    iVar4 = ((int)param_4 < 8) * param_4 + (uint)((int)param_4 >= 8) * 8;
    param_4 = param_4 - iVar4;
    *param_6 = uVar7 + iVar4;
    memw();
  }
  memw();
  return 0;
}

