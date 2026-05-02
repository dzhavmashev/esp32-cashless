// Function : FUN_400e5ecc
// Address  : 0x400e5ecc
// Size     : 659 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e5ecc(int *param_1)

{
  ulonglong uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  float fVar11;
  undefined1 auStack_2a0 [8];
  undefined8 uStack_298;
  undefined1 auStack_290 [16];
  int iStack_280;
  undefined1 auStack_27c [16];
  byte bStack_26c;
  int iStack_268;
  int iStack_264;
  undefined1 auStack_260 [16];
  undefined1 auStack_250 [24];
  undefined1 auStack_238 [532];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_27c,&DAT_3f42161d);
  FUN_400f0be8(auStack_260,&DAT_3f42161d);
  piVar6 = (int *)&DAT_3f42161d;
  do {
    iStack_280 = *param_1;
    FUN_400f0d18(auStack_27c,param_1 + 0xf);
    fVar11 = (float)param_1[0x15];
    uVar1 = (ulonglong)(fVar11 * 1.0);
    bVar2 = uVar1 >> 0x10 != 0;
    bStack_26c = ((!NAN(fVar11) && !bVar2) && -1 < (longlong)uVar1) * (char)uVar1 -
                 (NAN(fVar11) || bVar2);
    iStack_268 = param_1[0x13];
    iStack_264 = param_1[0x14];
    iVar7 = *param_1;
    if (iVar7 == 3) {
      piVar6 = (int *)0x3f407a64;
LAB_400e5fbb:
      piVar10 = piVar6;
    }
    else if (iVar7 < 4) {
      piVar10 = (int *)0x3f407a4f;
      if (iVar7 != 1) goto LAB_400e5fbb;
    }
    else {
      piVar10 = (int *)0x3f407a79;
      if ((iVar7 != 4) && (piVar10 = (int *)0x3f407a8c, iVar7 != 5)) goto LAB_400e5fbb;
    }
    FUN_400f0d70(auStack_260,piVar10);
    if (param_1[0x72] != 0) {
      (*(code *)param_1[0x73])(param_1 + 0x70,&iStack_280);
    }
    FUN_40183bd4(auStack_250);
    uVar4 = FUN_400d4db0(auStack_238,"rotocol version",auStack_250);
    uStack_298._0_4_ = uVar4;
    uStack_298._4_4_ = auStack_250;
    FUN_40183db8(auStack_27c,uVar4,auStack_250);
    FUN_400e6d7c(auStack_290,param_1[0x3e]);
    uStack_298._0_4_ = FUN_400d4db0(auStack_238,"trieved",auStack_250);
    uStack_298._4_4_ = auStack_250;
    FUN_40183db8(auStack_290,(undefined4)uStack_298,auStack_250);
    FUN_400f0a50(auStack_290);
    iVar7 = *param_1;
    pcVar8 = "talling";
    if (((iVar7 != 3) && (pcVar8 = "loading", iVar7 != 4)) && (pcVar8 = "e state", iVar7 != 5)) {
      pcVar8 = "rifying";
    }
    uVar4 = FUN_400d4db0(auStack_238," update",auStack_250);
    FUN_400e4768(pcVar8,uVar4);
    uVar9 = (uint)bStack_26c;
    puVar5 = (uint *)FUN_400d4db0(auStack_238,"eady in progress",auStack_250);
    iVar7 = iStack_268;
    if (puVar5 != (uint *)0x0) {
      *(byte *)(puVar5 + 2) = (byte)puVar5[2] & 0x80 | 8;
      *puVar5 = uVar9;
      puVar5[1] = 0;
    }
    piVar6 = (int *)FUN_400d4db0(auStack_238,"e");
    iVar3 = iStack_264;
    if (piVar6 != (int *)0x0) {
      *(byte *)(piVar6 + 2) = *(byte *)(piVar6 + 2) & 0x80 | 8;
      *piVar6 = iVar7;
      piVar6[1] = 0;
    }
    piVar6 = (int *)FUN_400d4db0(auStack_238,"nloaded");
    if (piVar6 != (int *)0x0) {
      *(byte *)(piVar6 + 2) = *(byte *)(piVar6 + 2) & 0x80 | 8;
      *piVar6 = iVar3;
      piVar6[1] = 0;
    }
    FUN_400f0be8(auStack_290,"l_bytes");
    uStack_298 = FUN_401841b0(auStack_250);
    FUN_400e58d4(param_1,auStack_290,&uStack_298);
    FUN_400f0a50(auStack_290);
    iVar7 = FUN_400f1a9c();
    param_1[0x16] = iVar7;
    FUN_400f0a50(auStack_260);
    FUN_400f0a50(auStack_27c);
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
    FUN_400f0a50((int)auStack_2a0 * 2 + 0x2a0);
    piVar6 = &iStack_280;
    FUN_400f0a50(auStack_260);
    FUN_400f0a50(auStack_27c);
    thunk_FUN_401710d8(param_1);
  } while( true );
}

