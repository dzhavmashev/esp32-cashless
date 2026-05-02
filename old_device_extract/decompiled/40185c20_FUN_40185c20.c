// Function : FUN_40185c20
// Address  : 0x40185c20
// Size     : 998 bytes


void FUN_40185c20(uint param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar5 = 0;
  puVar3 = param_3;
  puVar4 = param_2;
  uVar7 = param_1;
  while (0xf < uVar7) {
    uVar1 = *puVar4;
    uVar2 = uVar5 + param_4 * uVar1;
    uVar8 = *puVar3;
    uVar6 = uVar8 + uVar2;
    *puVar3 = uVar6;
    uVar5 = (uint)(uVar6 < uVar8) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar1 >> 0x20);
    uVar8 = puVar4[1];
    uVar2 = uVar5 + param_4 * uVar8;
    uVar1 = puVar3[1];
    uVar6 = uVar1 + uVar2;
    puVar3[1] = uVar6;
    uVar8 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar5 = puVar4[2];
    uVar2 = uVar8 + param_4 * uVar5;
    uVar1 = puVar3[2];
    uVar6 = uVar1 + uVar2;
    puVar3[2] = uVar6;
    uVar5 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar8) + (int)((ulonglong)param_4 * (ulonglong)uVar5 >> 0x20);
    uVar8 = puVar4[3];
    uVar2 = uVar5 + param_4 * uVar8;
    uVar1 = puVar3[3];
    uVar6 = uVar1 + uVar2;
    puVar3[3] = uVar6;
    uVar8 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar5 = puVar4[4];
    uVar2 = uVar8 + param_4 * uVar5;
    uVar1 = puVar3[4];
    uVar6 = uVar1 + uVar2;
    puVar3[4] = uVar6;
    uVar5 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar8) + (int)((ulonglong)param_4 * (ulonglong)uVar5 >> 0x20);
    uVar8 = puVar4[5];
    uVar2 = uVar5 + param_4 * uVar8;
    uVar1 = puVar3[5];
    uVar6 = uVar1 + uVar2;
    puVar3[5] = uVar6;
    uVar8 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar5 = puVar4[6];
    uVar2 = uVar8 + param_4 * uVar5;
    uVar1 = puVar3[6];
    uVar6 = uVar1 + uVar2;
    puVar3[6] = uVar6;
    uVar5 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar8) + (int)((ulonglong)param_4 * (ulonglong)uVar5 >> 0x20);
    uVar8 = puVar4[7];
    uVar2 = uVar5 + param_4 * uVar8;
    uVar1 = puVar3[7];
    uVar6 = uVar1 + uVar2;
    puVar3[7] = uVar6;
    uVar8 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar5 = puVar4[8];
    uVar2 = uVar8 + param_4 * uVar5;
    uVar1 = puVar3[8];
    uVar6 = uVar1 + uVar2;
    puVar3[8] = uVar6;
    uVar5 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar8) + (int)((ulonglong)param_4 * (ulonglong)uVar5 >> 0x20);
    uVar8 = puVar4[9];
    uVar2 = uVar5 + param_4 * uVar8;
    uVar1 = puVar3[9];
    uVar6 = uVar1 + uVar2;
    puVar3[9] = uVar6;
    uVar8 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar5 = puVar4[10];
    uVar2 = uVar8 + param_4 * uVar5;
    uVar1 = puVar3[10];
    uVar6 = uVar1 + uVar2;
    puVar3[10] = uVar6;
    uVar5 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar8) + (int)((ulonglong)param_4 * (ulonglong)uVar5 >> 0x20);
    uVar8 = puVar4[0xb];
    uVar2 = uVar5 + param_4 * uVar8;
    uVar1 = puVar3[0xb];
    uVar6 = uVar1 + uVar2;
    puVar3[0xb] = uVar6;
    uVar8 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar5 = puVar4[0xc];
    uVar2 = uVar8 + param_4 * uVar5;
    uVar1 = puVar3[0xc];
    uVar6 = uVar1 + uVar2;
    puVar3[0xc] = uVar6;
    uVar5 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar8) + (int)((ulonglong)param_4 * (ulonglong)uVar5 >> 0x20);
    uVar8 = puVar4[0xd];
    uVar2 = uVar5 + param_4 * uVar8;
    uVar1 = puVar3[0xd];
    uVar6 = uVar1 + uVar2;
    puVar3[0xd] = uVar6;
    uVar8 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar5 = puVar4[0xe];
    uVar2 = uVar8 + param_4 * uVar5;
    uVar1 = puVar3[0xe];
    uVar6 = uVar1 + uVar2;
    puVar3[0xe] = uVar6;
    uVar5 = (uint)(uVar6 < uVar1) +
            (uint)(uVar2 < uVar8) + (int)((ulonglong)param_4 * (ulonglong)uVar5 >> 0x20);
    uVar2 = puVar4[0xf];
    uVar6 = uVar5 + param_4 * uVar2;
    uVar1 = puVar3[0xf];
    uVar7 = uVar7 - 0x10;
    uVar8 = uVar1 + uVar6;
    puVar4 = puVar4 + 0x10;
    puVar3[0xf] = uVar8;
    puVar3 = puVar3 + 0x10;
    uVar5 = (uint)(uVar8 < uVar1) +
            (uint)(uVar6 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar2 >> 0x20);
    memw();
  }
  uVar7 = param_1 & 0xf;
  param_2 = param_2 + (param_1 >> 4) * 0x10;
  param_3 = param_3 + (param_1 >> 4) * 0x10;
  if (7 < uVar7) {
    uVar8 = *param_2;
    uVar1 = uVar5 + param_4 * uVar8;
    uVar6 = *param_3;
    uVar2 = uVar1 + uVar6;
    *param_3 = uVar2;
    uVar8 = (uint)(uVar2 < uVar6) +
            (uint)(uVar1 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20);
    uVar6 = param_2[1];
    uVar1 = uVar8 + param_4 * uVar6;
    uVar5 = param_3[1];
    uVar2 = uVar1 + uVar5;
    param_3[1] = uVar2;
    uVar8 = (uint)(uVar2 < uVar5) +
            (int)((ulonglong)param_4 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar1 < uVar8);
    uVar6 = param_2[2];
    uVar1 = uVar8 + param_4 * uVar6;
    uVar5 = param_3[2];
    uVar2 = uVar1 + uVar5;
    param_3[2] = uVar2;
    uVar8 = (uint)(uVar2 < uVar5) +
            (int)((ulonglong)param_4 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar1 < uVar8);
    uVar6 = param_2[3];
    uVar1 = uVar8 + param_4 * uVar6;
    uVar5 = param_3[3];
    uVar2 = uVar1 + uVar5;
    param_3[3] = uVar2;
    uVar8 = (uint)(uVar2 < uVar5) +
            (int)((ulonglong)param_4 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar1 < uVar8);
    uVar6 = param_2[4];
    uVar1 = uVar8 + param_4 * uVar6;
    uVar5 = param_3[4];
    uVar2 = uVar1 + uVar5;
    param_3[4] = uVar2;
    uVar8 = (uint)(uVar2 < uVar5) +
            (int)((ulonglong)param_4 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar1 < uVar8);
    uVar6 = param_2[5];
    uVar1 = uVar8 + param_4 * uVar6;
    uVar5 = param_3[5];
    uVar2 = uVar1 + uVar5;
    param_3[5] = uVar2;
    uVar8 = (uint)(uVar2 < uVar5) +
            (int)((ulonglong)param_4 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar1 < uVar8);
    uVar6 = param_2[6];
    uVar1 = uVar8 + param_4 * uVar6;
    uVar5 = param_3[6];
    uVar2 = uVar1 + uVar5;
    param_3[6] = uVar2;
    uVar2 = (uint)(uVar2 < uVar5) +
            (int)((ulonglong)param_4 * (ulonglong)uVar6 >> 0x20) + (uint)(uVar1 < uVar8);
    uVar8 = param_2[7];
    uVar5 = uVar2 + param_4 * uVar8;
    uVar6 = param_3[7];
    uVar1 = uVar5 + uVar6;
    param_3[7] = uVar1;
    uVar5 = (uint)(uVar1 < uVar6) +
            (int)((ulonglong)param_4 * (ulonglong)uVar8 >> 0x20) + (uint)(uVar5 < uVar2);
    uVar7 = uVar7 - 8;
    param_3 = param_3 + 8;
    param_2 = param_2 + 8;
  }
  puVar3 = param_3 + uVar7;
  while (param_3 != puVar3) {
    uVar7 = *param_2;
    uVar1 = uVar5 + param_4 * uVar7;
    uVar6 = *param_3;
    param_2 = param_2 + 1;
    uVar2 = uVar6 + uVar1;
    *param_3 = uVar2;
    param_3 = param_3 + 1;
    uVar5 = (uint)(uVar2 < uVar6) +
            (uint)(uVar1 < uVar5) + (int)((ulonglong)param_4 * (ulonglong)uVar7 >> 0x20);
    memw();
  }
  while (uVar5 != 0) {
    uVar7 = *param_3;
    *param_3 = uVar5 + uVar7;
    uVar5 = (uint)(uVar5 + uVar7 < uVar5);
    param_3 = param_3 + 1;
    memw();
  }
  memw();
  return;
}

