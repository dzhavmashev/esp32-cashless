// Function : FUN_400f2f64
// Address  : 0x400f2f64
// Size     : 206 bytes


int FUN_400f2f64(byte *param_1,int param_2,undefined1 *param_3,int *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  byte bVar7;
  
  pbVar4 = param_1 + param_2;
  bVar7 = *(byte *)(param_4 + 1);
  iVar6 = *param_4;
  puVar5 = param_3;
  if (iVar6 == 1) goto LAB_400f2fb3;
  if (iVar6 == 0) goto LAB_400f2f83;
  pbVar3 = param_1;
  if (iVar6 == 2) {
    while (pbVar3 != pbVar4) {
      param_1 = pbVar3 + 1;
      bVar1 = *pbVar3;
      uVar2 = FUN_400f2f4c(bVar7 | bVar1 >> 6);
      bVar7 = bVar1 & 0x3f;
      *puVar5 = uVar2;
      uVar2 = FUN_400f2f4c(bVar7);
      puVar5[1] = uVar2;
      puVar5 = puVar5 + 2;
LAB_400f2f83:
      if (param_1 == pbVar4) {
        *param_4 = 0;
        *(byte *)(param_4 + 1) = bVar7;
        return (int)puVar5 - (int)param_3;
      }
      bVar7 = *param_1;
      uVar2 = FUN_400f2f4c(bVar7 >> 2);
      *puVar5 = uVar2;
      param_1 = param_1 + 1;
      bVar7 = (bVar7 & 3) << 4;
      puVar5 = puVar5 + 1;
LAB_400f2fb3:
      if (param_1 == pbVar4) {
        *param_4 = 1;
        *(byte *)(param_4 + 1) = bVar7;
        return (int)puVar5 - (int)param_3;
      }
      bVar1 = *param_1;
      uVar2 = FUN_400f2f4c(bVar7 | bVar1 >> 4);
      *puVar5 = uVar2;
      bVar7 = (bVar1 & 0xf) << 2;
      puVar5 = puVar5 + 1;
      pbVar3 = param_1 + 1;
    }
    *param_4 = 2;
    *(byte *)(param_4 + 1) = bVar7;
    iVar6 = (int)puVar5 - (int)param_3;
  }
  else {
    iVar6 = 0;
  }
  return iVar6;
}

