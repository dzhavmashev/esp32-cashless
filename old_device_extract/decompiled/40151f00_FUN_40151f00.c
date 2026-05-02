// Function : FUN_40151f00
// Address  : 0x40151f00
// Size     : 229 bytes


uint FUN_40151f00(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  byte local_30 [48];
  
  uVar7 = **(uint **)(param_2 + 0x2c) & 0x8000;
  pbVar6 = *(byte **)(*(int *)(param_2 + 4) + 4);
  if (uVar7 == 0) {
    bVar1 = pbVar6[0xc];
    bVar2 = pbVar6[0xd];
  }
  else {
    bVar1 = pbVar6[0x14];
    bVar2 = pbVar6[0x15];
  }
  sVar3 = CONCAT11(bVar2,bVar1);
  if ((sVar3 == -0x7178) || (sVar3 == -0x4b78)) {
    uVar5 = 7;
  }
  else {
    uVar5 = 7;
    if (((*pbVar6 & 1) == 0) && ((*(uint *)(param_1 + 0xc) & 2) != 0)) {
      if (sVar3 == 8) {
        pbVar4 = pbVar6 + 0x16;
        if (uVar7 == 0) {
          pbVar4 = pbVar6 + 0xe;
        }
        uVar5 = (uint)(pbVar4[1] >> 5);
      }
      else if (sVar3 == -0x227a) {
        pbVar4 = pbVar6 + 0xe;
        if (uVar7 != 0) {
          pbVar4 = pbVar6 + 0x16;
        }
        uVar5 = (uint)(*(int *)pbVar4 << 0x18) >> 0x19 & 7;
      }
      else {
        uVar5 = *pbVar6 & 1;
        if (sVar3 == -0x1112) {
          uVar5 = 5;
        }
      }
    }
  }
  (*(code *)&SUB_4008b3d0)(local_30,"utput.c",8);
  if ((uVar5 == 0) || (uVar5 == 3)) {
    uVar7 = 2;
  }
  else {
    if (uVar5 < 3) {
      return uVar5;
    }
    uVar7 = 1;
    if (5 < uVar5) {
      uVar7 = 0;
    }
  }
  do {
    if (*(char *)(param_1 + uVar7 * 7 + 0x89) == '\0') {
      return uVar5;
    }
    uVar5 = (uint)local_30[uVar7 * 2 + 1];
    uVar7 = (uint)local_30[uVar7 * 2];
  } while (uVar7 != 3);
  return uVar5;
}

