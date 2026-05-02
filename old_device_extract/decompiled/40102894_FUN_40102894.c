// Function : FUN_40102894
// Address  : 0x40102894
// Size     : 326 bytes


void FUN_40102894(ushort *param_1,byte *param_2,undefined1 *param_3,int *param_4,byte *param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  
  *param_5 = 0;
  memw();
  uVar9 = 0;
  uVar6 = (uint)*param_1;
  uVar7 = uVar6 & 0x300;
  uVar3 = (uint)(uVar7 == 0x300);
  uVar1 = *param_1 >> 2;
  uVar4 = uVar1 & 3;
  if (uVar4 == 2) {
    if (((int)uVar6 >> 4 & 8U) == 0) {
      uVar6 = uVar6 & 0xffffff8f;
      uVar9 = 0;
    }
    else {
      uVar6 = uVar6 & 0x7f8f;
      puVar5 = param_1 + 0xc;
      if (uVar7 == 0x300) {
        puVar5 = param_1 + 0xf;
      }
      *param_5 = (byte)*puVar5 & 0xf;
      memw();
      uVar9 = 1;
      memw();
    }
  }
  else if ((uVar1 & 3) == 0) {
    *param_5 = 0x10;
    memw();
    memw();
    uVar9 = uVar4;
  }
  param_3[1] = (byte)((uVar6 & 0xffffc7ff) >> 8) | 0x40;
  *param_3 = (char)(uVar6 & 0xffffc7ff);
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(param_3 + 2,param_1 + 2,0x12);
  uVar1 = param_1[0xb];
  param_3[0x15] = 0;
  param_3[0x14] = (byte)uVar1 & 0xf;
  memw();
  memw();
  iVar2 = (*(code *)&SUB_4008b3d0)(param_3 + 0x16,param_1 + 0xc,(uVar3 * 3 + uVar9) * 2);
  pbVar8 = (byte *)(iVar2 + uVar3 * 6);
  if (uVar9 != 0) {
    *pbVar8 = *pbVar8 & 0xf;
    pbVar8[1] = 0;
    memw();
    pbVar8 = pbVar8 + 2;
  }
  *param_4 = (int)pbVar8 - (int)param_3;
  memw();
  (*(code *)&SUB_4008b3d0)(param_5 + 1,param_1 + 5,6);
  param_5[7] = param_2[7];
  memw();
  param_5[8] = param_2[6];
  memw();
  param_5[9] = param_2[5];
  memw();
  param_5[10] = param_2[4];
  memw();
  param_5[0xb] = param_2[1];
  memw();
  param_5[0xc] = *param_2;
  memw();
  memw();
  return;
}

