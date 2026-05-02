// Function : FUN_4014c490
// Address  : 0x4014c490
// Size     : 220 bytes


undefined4 FUN_4014c490(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  
  iVar6 = *param_1;
  (*(code *)&SUB_4008b530)((int)param_1 + 0x73,0,0x10);
  puVar10 = (undefined1 *)(iVar6 + 0x16a);
  cVar4 = '\0';
  cVar8 = '\0';
  uVar5 = 0;
  uVar11 = 0;
  for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(iVar6 + 0x169); iVar7 = iVar7 + 1) {
    uVar1 = *puVar10;
    memw();
    iVar3 = FUN_40186900(param_2,param_3,uVar1);
    if (iVar3 != 0) {
      bVar2 = *(byte *)((int)param_1 + 0x73);
      uVar9 = bVar2 + 1;
      *(char *)((int)param_1 + 0x73) = (char)uVar9;
      *(undefined1 *)((int)param_1 + bVar2 + 0x74) = uVar1;
      memw();
      bVar2 = *(byte *)((int)param_1 + (uVar9 & 0xff) + 0x73);
      uVar9 = (uint)bVar2;
      if ((char)bVar2 < '\0') {
        memw();
        uVar9 = uVar9 & 0x7f;
        cVar8 = cVar8 + '\x01';
        uVar11 = (uVar11 < uVar9) * uVar9 + (uVar11 >= uVar9) * uVar11;
      }
      else {
        cVar4 = cVar4 + '\x01';
        uVar5 = (uVar5 < uVar9) * uVar9 + (uVar5 >= uVar9) * uVar5;
      }
    }
    puVar10 = puVar10 + 1;
  }
  *(char *)(param_1 + 0xbb) = (char)uVar11;
  *(char *)((int)param_1 + 0x2ed) = (char)uVar5;
  memw();
  if (cVar8 != '\x04') {
    *(undefined1 *)(param_1 + 0xbc) = 1;
    memw();
  }
  if ((cVar4 == '\x01' && uVar5 == 0x6c) || (uVar5 != 0x6c || cVar4 == '\x01' && uVar5 == 0x6c)) {
    *(undefined1 *)((int)param_1 + 0x2f1) = 1;
    memw();
    memw();
  }
  return 0;
}

