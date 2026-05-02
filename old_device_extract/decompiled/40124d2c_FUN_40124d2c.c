// Function : FUN_40124d2c
// Address  : 0x40124d2c
// Size     : 284 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40124d2c(int *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined1 *puVar8;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [32];
  int *piStack_24;
  
  piVar7 = param_1 + 0x40;
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  iVar5 = param_1[1];
  *(byte *)(param_1 + 0x67) = *(byte *)(param_1 + 0x67) | 1;
  memw();
  param_1[5] = 1;
  iVar3 = param_1[0xc];
  param_1[0xc] = iVar3 + 1;
  if (iVar3 + 1 < 5) {
    if (param_1[0x6d] == 1) {
      param_1[0x61] = 0;
    }
    param_1[0xd] = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    if (*(int *)(*param_1 + 0x48) != 0) goto LAB_40124e35;
    puVar4 = (undefined1 *)(iVar5 + *(int *)(iVar5 + 0x18) * 0x20 + 0x48);
    goto LAB_40124d86;
  }
LAB_40124e1e:
  do {
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_40124e35:
    iVar3 = FUN_40102858(auStack_44,*(undefined4 *)(iVar5 + 0x14));
  } while (iVar3 < 0);
  puVar4 = auStack_44;
LAB_40124d86:
  iVar3 = *(int *)(iVar5 + 0x14);
  puVar8 = puVar4 + iVar3;
  puVar1 = puVar4;
  if (param_1[0x6d] == 2) goto code_r0x40124d92;
  goto LAB_40124dde;
code_r0x40124d92:
  iVar6 = 0x1e;
  if ((*(byte *)(piVar7 + 0x27) & 0x10) == 0) {
    iVar6 = 0;
  }
  memw();
  puVar1 = (undefined1 *)(*(code *)&SUB_40094d60)(iVar3 + 8 + iVar6);
  if (puVar1 != (undefined1 *)0x0) {
    piVar7 = (int *)(*(uint *)(iVar5 + 0x18) & 3);
    uStack_4e = SUB41(piVar7,0);
    uStack_4d = 0;
    memw();
    memw();
    uVar2 = FUN_40125ca4(puVar1,0xfac01,&uStack_4e,2,puVar4,iVar3);
    puVar8 = (undefined1 *)FUN_40124380(param_1,uVar2);
LAB_40124dde:
    uVar2 = 0x380;
    if (param_1[0x48] == 0) {
      uVar2 = 0x3c0;
    }
    memw();
    FUN_40124bb4(*param_1,param_1,uVar2,&uStack_4c,iVar5 + 0xa8,puVar1,(int)puVar8 - (int)puVar1,
                 *(undefined4 *)(iVar5 + 0x18),1);
    iVar5 = 0x3c0;
    if (param_1[0x6d] == 2) {
      (*(code *)&SUB_40094d80)(puVar1);
      iVar5 = 0x3c0;
    }
  }
  goto LAB_40124e1e;
}

