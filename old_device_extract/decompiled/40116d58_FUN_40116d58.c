// Function : FUN_40116d58
// Address  : 0x40116d58
// Size     : 333 bytes


byte FUN_40116d58(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  uint local_30 [3];
  uint auStack_24 [9];
  
  puVar5 = local_30;
  bVar1 = *param_1;
LAB_40116d6d:
  uVar4 = (uint)bVar1;
  if ((*(byte *)(uVar4 + 0x3ff96355) & 4) != 0) {
    iVar8 = 10;
    if (uVar4 == 0x30) {
      uVar4 = (uint)param_1[1];
      if ((uVar4 & 0xffffffdf) == 0x58) {
        uVar4 = (uint)param_1[2];
        iVar8 = 0x10;
        param_1 = param_1 + 2;
      }
      else {
        param_1 = param_1 + 1;
        iVar8 = 8;
      }
    }
    uVar6 = 0;
    pbVar7 = param_1;
    do {
      uVar10 = CONCAT44(local_30,uVar6);
      bVar1 = *(byte *)(uVar4 + 0x3ff96355);
      if ((bVar1 & 4) == 0) {
        if ((iVar8 != 0x10) || ((bVar1 & 0x44) == 0)) goto LAB_40116de0;
        iVar9 = 0x41;
        if ((bVar1 & 3) == 2) {
          iVar9 = 0x61;
        }
        uVar6 = (uVar4 + 10) - iVar9 | uVar6 << 4;
      }
      else {
        uVar6 = (iVar8 * uVar6 + uVar4) - 0x30;
      }
      uVar4 = (uint)pbVar7[1];
      pbVar7 = pbVar7 + 1;
    } while( true );
  }
LAB_40116ea5:
  bVar2 = 0;
  goto LAB_40116e7e;
LAB_40116de0:
  if (uVar4 != 0x2e) {
    if ((uVar4 != 0) && (bVar2 = bVar1 & 8, (bVar1 & 8) == 0)) goto LAB_40116e7e;
    iVar8 = (int)puVar5 - (int)local_30 >> 2;
    iVar9 = iVar8 + 1;
    if (iVar9 == 2) {
      bVar2 = 0;
      if ((0xffffff < uVar6) || (0xff < local_30[0])) goto LAB_40116e7e;
      uVar4 = local_30[0] << 0x18;
      goto LAB_40116e6f;
    }
    if (2 < iVar9) goto LAB_40116e2a;
    bVar2 = 0;
    if (iVar8 == -1) goto LAB_40116e7e;
    if (iVar9 == 1) goto LAB_40116e72;
    goto LAB_40116e18;
  }
  if (puVar5 == auStack_24) goto LAB_40116ea5;
  *puVar5 = uVar6;
  param_1 = pbVar7 + 1;
  puVar5 = puVar5 + 1;
  bVar1 = pbVar7[1];
  memw();
  goto LAB_40116d6d;
LAB_40116e18:
  uVar10 = (*(code *)&SUB_40094c54)("opt_src",0xf9,"_addr.c"," ERR_OK unhandled");
LAB_40116e2a:
  puVar5 = (uint *)((ulonglong)uVar10 >> 0x20);
  uVar6 = (uint)uVar10;
  if (iVar9 != 3) goto code_r0x40116e2d;
  bVar2 = 0;
  if (((uVar6 < 0x10000) && (*puVar5 < 0x100)) && (puVar5[1] < 0x100)) {
    uVar4 = *puVar5 << 0x18 | puVar5[1] << 0x10;
LAB_40116e6f:
    uVar6 = uVar6 | uVar4;
    goto LAB_40116e72;
  }
  goto LAB_40116e7e;
code_r0x40116e2d:
  if (iVar9 == 4) goto code_r0x40116e30;
  goto LAB_40116e18;
code_r0x40116e30:
  bVar2 = 0;
  if ((((uVar6 < 0x100) && (*puVar5 < 0x100)) && (puVar5[1] < 0x100)) && (puVar5[2] < 0x100)) {
    uVar6 = uVar6 | *puVar5 << 0x18 | puVar5[1] << 0x10 | puVar5[2] << 8;
LAB_40116e72:
    bVar2 = 1;
    if (param_2 != (undefined4 *)0x0) {
      uVar3 = FUN_40109eec(uVar6);
      bVar2 = 1;
      *param_2 = uVar3;
    }
  }
LAB_40116e7e:
  memw();
  return bVar2;
}

