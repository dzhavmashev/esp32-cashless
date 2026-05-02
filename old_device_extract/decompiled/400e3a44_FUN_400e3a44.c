// Function : FUN_400e3a44
// Address  : 0x400e3a44
// Size     : 594 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e3a44(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_90;
  undefined1 *puStack_8c;
  undefined1 *puStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined1 auStack_58 [20];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400d7378(auStack_78,0x1000,0);
  uStack_90 = FUN_400d4db0(auStack_58,"ce_info",auStack_70);
  puStack_8c = auStack_70;
  FUN_40183db8(param_2,uStack_90,auStack_70);
  uStack_90 = FUN_400d4db0(auStack_58,"Unknown command",auStack_70);
  puStack_8c = auStack_70;
  FUN_40183db8(param_3,uStack_90,auStack_70);
  pcVar4 = "lient: ";
  if (*param_4 != 0) {
    pcVar4 = "all";
  }
  uVar1 = FUN_400d4db0(auStack_58,"offline status",auStack_70);
  FUN_400e0404(pcVar4,uVar1);
  uStack_90 = FUN_400d4db0(auStack_58," an SSL message",auStack_70);
  puStack_8c = auStack_70;
  FUN_40183db8(param_4 + 1,uStack_90,auStack_70);
  iVar5 = param_4[5];
  if ((iVar5 != 0) && ((*(byte *)(iVar5 + 0x28) & 0x60) != 0)) {
    iVar6 = 0;
    iVar5 = *(int *)(iVar5 + 0x20);
    while (iVar5 != 0) {
      iVar6 = iVar6 + 1;
      iVar5 = (*(code *)&LAB_40183a9a_2)();
    }
    if (iVar6 != 0) {
      iVar5 = FUN_400dc9cc(auStack_58,"d ASN.1 data",auStack_70);
      puVar2 = (undefined1 *)0x0;
      if (iVar5 != 0) {
        puVar2 = (undefined1 *)(*(code *)&LAB_40184133_1)();
      }
      uVar7 = FUN_401841b0(param_4[5] + 8);
      if ((int *)uVar7 != (int *)0x0) {
        for (iVar5 = *(int *)uVar7; iVar5 != 0; iVar5 = (*(code *)&LAB_40183a9a_2)(iVar5)) {
          iVar6 = iVar5;
          FUN_400e04f0(&uStack_a4,(int)((ulonglong)uVar7 >> 0x20));
          uVar1 = uStack_98;
          uStack_80 = uStack_a0;
          uStack_7c = uStack_9c;
          uStack_84 = uStack_a4;
          puStack_8c = puVar2;
          puStack_88 = auStack_70;
          uVar8 = FUN_40184114(&uStack_84);
          uVar3 = FUN_400e13c4(puVar2,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20),iVar6,puStack_88);
          FUN_400e1000(uVar3,uVar1,auStack_70);
        }
      }
    }
  }
  FUN_400f0be8(auStack_44,&DAT_3f42161d);
  FUN_400d5948(auStack_58,auStack_44);
  uVar1 = *param_1;
  FUN_400f0be8(auStack_34,"mand_id");
  FUN_400dba34(uVar1,auStack_34,auStack_44);
  FUN_400f0a50(auStack_34);
  FUN_400f0a50(auStack_44);
  FUN_400d73a8(auStack_78);
  iVar5 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return;
  }
  func_0x40082ecc();
  FUN_400f0a50(auStack_34);
  do {
    FUN_400f0a50(auStack_44);
    FUN_400d73a8(auStack_78);
    thunk_FUN_401710d8(iVar5);
  } while( true );
}

