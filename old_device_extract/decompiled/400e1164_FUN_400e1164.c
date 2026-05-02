// Function : FUN_400e1164
// Address  : 0x400e1164
// Size     : 468 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e1164(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined8 local_e0;
  undefined1 auStack_d8 [12];
  char *pcStack_cc;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [40];
  undefined4 auStack_98 [2];
  undefined1 auStack_90 [44];
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  undefined4 *puStack_24;
  
  memw();
  param_3 = param_3 + 0x18;
  memw();
  puStack_24 = _DAT_3ffc5708;
  FUN_400d4330(param_3,"command_id");
  uVar1 = FUN_400e059c();
  FUN_400f0be8(auStack_64,uVar1);
  FUN_400d7378(auStack_c8,0x400,0);
  iVar2 = FUN_400d4330(param_3,"Missing params");
  if (iVar2 != 0) {
    auStack_98[0] = FUN_400d4330(param_3,"Missing params");
    FUN_400e1028(auStack_c0,auStack_98);
  }
  FUN_400d7378(auStack_98,0x200,0);
  local_e0 = FUN_400e06e4(auStack_90);
  auStack_d8._0_8_ = FUN_401841b0(auStack_c0);
  iVar2 = FUN_400e59bc(0x3ffc4ae8,auStack_64,auStack_d8,&local_e0);
  puVar4 = (undefined4 *)&DAT_3ffc5708;
  puVar5 = param_1 + 1;
  auStack_d8._4_8_ = local_e0;
  if (iVar2 == 0) goto LAB_400e12f5;
  pcStack_cc = "itiated";
  uVar1 = FUN_400e0768(auStack_d8," OID is unknown");
  FUN_400f0be8(auStack_54,uVar1);
  FUN_400f0be8(auStack_44,"version");
  piVar3 = (int *)FUN_400f10c0(auStack_44,auStack_54);
  if ((*(byte *)((int)piVar3 + 0xf) & 0x80) == 0) {
    piVar3 = (int *)*piVar3;
  }
  FUN_400f0be8(auStack_34,piVar3);
  *param_1 = 0;
  FUN_400f0d4c(puVar5,auStack_34);
  param_1[5] = 0;
  FUN_400f0a50(auStack_34);
  FUN_400f0a50(auStack_44);
  puVar4 = (undefined4 *)&DAT_3ffc5708;
  iVar2 = 0x8c;
  while( true ) {
    FUN_400f0a50((int)&local_e0 + iVar2);
    FUN_400d73a8(auStack_98);
    FUN_400d73a8(auStack_c8);
    FUN_400f0a50(auStack_64);
    puVar5 = puStack_24;
    memw();
    memw();
    puVar4 = (undefined4 *)*puVar4;
    if (puStack_24 == puVar4) break;
    func_0x40082ecc();
LAB_400e12f5:
    pcStack_cc = " an SSL message";
    uVar1 = FUN_400e0768(auStack_d8,"ersion ");
    FUN_400f0be8(auStack_34,uVar1);
    *param_1 = 1;
    FUN_400f0d4c(puVar5,auStack_34);
    param_1[5] = 0;
    iVar2 = 0xac;
  }
  return;
}

