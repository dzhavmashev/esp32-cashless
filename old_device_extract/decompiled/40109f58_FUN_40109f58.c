// Function : FUN_40109f58
// Address  : 0x40109f58
// Size     : 274 bytes


void FUN_40109f58(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  undefined4 uVar8;
  byte *in_t0;
  
  iVar3 = 0x3ffc5d50;
  if (param_2 != 0) {
    pbVar7 = &DAT_3ffc5e74 + param_1 * 0x128;
    bVar1 = *pbVar7;
    if (*(char *)(param_2 + 0x14) != '\x06') goto LAB_40109f99;
    bVar4 = 1;
    if ((bVar1 & 0xfd) != 1) {
      uVar8 = 0x3ff;
      pbVar7 = in_t0;
      while( true ) {
        (*(code *)&SUB_40094c54)("esponse",uVar8,"ns_send","p_inpkt");
        in_t0 = pbVar7;
LAB_40109f99:
        if ((bVar1 & 0xfd) != 1) break;
        uVar8 = 0x402;
        pbVar7 = in_t0;
      }
      bVar4 = 0;
    }
    *pbVar7 = bVar4;
    memw();
  }
  puVar6 = (undefined4 *)&DAT_3ffc5d20;
  do {
    if (((code *)*puVar6 != (code *)0x0) && (*(byte *)(puVar6 + 2) == param_1)) {
      memw();
      (*(code *)*puVar6)(param_1 * 0x128 + 0x3ffc5d74,param_2,puVar6[1]);
      *puVar6 = 0;
    }
    puVar6 = puVar6 + 3;
  } while (puVar6 != (undefined4 *)0x3ffc5d50);
  uVar2 = 0;
  iVar5 = 4;
  while (((param_1 == uVar2 || (*(char *)(iVar3 + 0x1e) != '\x02')) ||
         (*(char *)(iVar3 + 0x23) != (&DAT_3ffc5d73)[param_1 * 0x128]))) {
    uVar2 = uVar2 + 1 & 0xff;
    iVar3 = iVar3 + 0x128;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
LAB_4010a022:
      iVar3 = param_1 * 0x128;
      if ((byte)(&DAT_3ffc5d73)[iVar3] < 4) {
        memw();
        FUN_40113ef0(*(undefined4 *)(&DAT_3ffc61f4 + (uint)(byte)(&DAT_3ffc5d73)[iVar3] * 4));
        *(undefined4 *)(&DAT_3ffc61f4 + (uint)(byte)(&DAT_3ffc5d73)[iVar3] * 4) = 0;
        (&DAT_3ffc5d73)[iVar3] = 4;
        memw();
      }
      memw();
      return;
    }
  }
  (&DAT_3ffc5d73)[param_1 * 0x128] = '\x04';
  memw();
  goto LAB_4010a022;
}

