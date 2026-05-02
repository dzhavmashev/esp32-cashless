// Function : FUN_400d6004
// Address  : 0x400d6004
// Size     : 765 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d6004(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  ushort uVar2;
  uint *puVar3;
  byte *pbVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined1 auStack_260 [16];
  undefined1 auStack_250 [24];
  undefined1 auStack_238 [532];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_40183bd4(auStack_250);
  bVar1 = *param_3;
  puVar3 = (uint *)FUN_400d4db0(auStack_238,"ic: %s\n");
  if (puVar3 != (uint *)0x0) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 8;
    *puVar3 = (uint)bVar1;
    puVar3[1] = 0;
  }
  bVar1 = param_3[1];
  puVar3 = (uint *)FUN_400d4db0(auStack_238,"nt_mode");
  if (puVar3 != (uint *)0x0) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 8;
    *puVar3 = (uint)bVar1;
    puVar3[1] = 0;
  }
  bVar1 = param_3[2];
  puVar3 = (uint *)FUN_400d4db0(auStack_238,"ce_type");
  if (puVar3 != (uint *)0x0) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 8;
    *puVar3 = (uint)bVar1;
    puVar3[1] = 0;
  }
  bVar1 = param_3[3];
  pbVar4 = (byte *)FUN_400d4db0(auStack_238,"rol_pin");
  if (pbVar4 != (byte *)0x0) {
    pbVar4[8] = pbVar4[8] & 0x80 | 6;
    *pbVar4 = bVar1;
  }
  uVar10 = *(undefined4 *)(param_3 + 8);
  puVar5 = (undefined8 *)FUN_400d4db0(auStack_238,"tension");
  if (puVar5 != (undefined8 *)0x0) {
    *(byte *)(puVar5 + 1) = *(byte *)(puVar5 + 1) & 0x80 | 0xc;
    uVar11 = (*(code *)&SUB_40002c34)(uVar10);
    *puVar5 = uVar11;
  }
  uVar2 = *(ushort *)(param_3 + 0xc);
  puVar3 = (uint *)FUN_400d4db0(auStack_238,"r_pulse");
  if (puVar3 != (uint *)0x0) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 8;
    *puVar3 = (uint)uVar2;
    puVar3[1] = 0;
  }
  puVar6 = (undefined4 *)FUN_400d4db0(auStack_238,"tion_ms");
  if (puVar6 != (undefined4 *)0x0) {
    *(byte *)(puVar6 + 2) = *(byte *)(puVar6 + 2) & 0x80 | 0x40;
    *puVar6 = 0;
    puVar6[1] = 0;
  }
  pbVar4 = param_3 + 0x14;
  for (uVar7 = 0; (bVar1 = param_3[100], uVar7 < bVar1 && (uVar7 != 10)); uVar7 = uVar7 + 1 & 0xff)
  {
    puVar8 = (undefined4 *)0x0;
    puVar9 = (undefined1 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      puVar8 = (undefined4 *)FUN_40183ab0(puVar6,auStack_250);
      puVar9 = auStack_250;
      if (puVar8 != (undefined4 *)0x0) {
        *(byte *)(puVar8 + 2) = *(byte *)(puVar8 + 2) & 0x80 | 0x20;
        *puVar8 = 0;
        puVar8[1] = 0;
      }
    }
    uVar10 = *(undefined4 *)pbVar4;
    if ((puVar8 != (undefined4 *)0x0) &&
       (puVar5 = (undefined8 *)FUN_400d4db0(puVar8,"Invalid amount",puVar9),
       puVar5 != (undefined8 *)0x0)) {
      *(byte *)(puVar5 + 1) = *(byte *)(puVar5 + 1) & 0x80 | 0xc;
      uVar11 = (*(code *)&SUB_40002c34)(uVar10);
      *puVar5 = uVar11;
    }
    uVar10 = *(undefined4 *)(pbVar4 + 4);
    if ((puVar8 != (undefined4 *)0x0) &&
       (puVar8 = (undefined4 *)FUN_400d4db0(puVar8,"e_table",puVar9), puVar8 != (undefined4 *)0x0))
    {
      *(byte *)(puVar8 + 2) = *(byte *)(puVar8 + 2) & 0x80 | 8;
      *puVar8 = uVar10;
      puVar8[1] = 0;
    }
    pbVar4 = pbVar4 + 8;
  }
  puVar3 = (uint *)FUN_400d4db0(auStack_238,"uration");
  if (puVar3 != (uint *)0x0) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 8;
    *puVar3 = (uint)bVar1;
    puVar3[1] = 0;
  }
  FUN_400f0be8(param_1,&DAT_3f42161d);
  FUN_400d5948(auStack_238,param_1);
  FUN_400f0be8(auStack_260,"le_size");
  uVar10 = FUN_400f10c0(auStack_260,param_1);
  FUN_400f0768(0x3ffc5490,uVar10);
  FUN_400f0a50(auStack_260);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_260);
    do {
      FUN_400f0a50(&DAT_3ffc5708);
      thunk_FUN_401710d8(param_1);
    } while( true );
  }
  return;
}

