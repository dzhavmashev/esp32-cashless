// Function : FUN_400eb540
// Address  : 0x400eb540
// Size     : 290 bytes


void FUN_400eb540(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  ushort uStack_3e;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar2 = (undefined4 *)FUN_40184578(param_1 + 0x68c);
  iVar3 = (*(code *)&LAB_401844da_2)();
  uVar4 = FUN_401844f4(puVar2);
  uVar5 = FUN_4018450c(puVar2);
  uStack_3e = *(ushort *)(puVar2 + 0x22);
  if (iVar3 != 1) goto LAB_400eb5d8;
  if (puVar2[0x25] + puVar2[0x24] == puVar2[0x26]) {
    FUN_400eb4ac(param_1,&DAT_3f40993c,&uStack_3e);
  }
  do {
    do {
      if (*(int *)(param_1 + 0x54) == 0) {
        return;
      }
      func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
      iVar6 = uStack_28;
      uStack_28._3_1_ = SUB41(iVar6,3);
      uStack_28._0_3_ = CONCAT12((char)uVar4,CONCAT11((char)uVar5,(char)iVar3));
      uStack_24 = CONCAT22(uStack_24._2_2_,uStack_3e);
      local_2c = puVar2[0x26];
      uStack_38 = puVar2[0x23];
      uVar5 = puVar2[0x24];
      uVar4 = puVar2[0x25];
      iStack_3c = (int)puVar2 + 7;
      puVar2 = &local_2c;
      uStack_34 = uVar5;
      uStack_30 = uVar4;
      if (*(int *)(param_1 + 0x54) != 0) {
        (**(code **)(param_1 + 0x58))
                  (param_1 + 0x4c,&uStack_28,&iStack_3c,&uStack_38,&uStack_34,&uStack_30,puVar2);
        func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
        return;
      }
      FUN_40170584();
      iVar3 = 0;
LAB_400eb5d8:
    } while (iVar3 != 2);
    uStack_28 = *(int *)(param_1 + 0x678);
    uStack_24 = 0;
    while (uStack_28 != 0) {
      iVar6 = FUN_401844a8(uStack_28 + 4);
      if ((iVar6 == 0x50) && (uVar7 = FUN_401844a0(uStack_28 + 4), uStack_3e == uVar7)) {
        bVar1 = false;
        goto LAB_400eb61c;
      }
      (*(code *)&LAB_40184487_1)(&uStack_28);
    }
    bVar1 = true;
LAB_400eb61c:
    if (puVar2[0x25] + puVar2[0x24] == puVar2[0x26]) {
      FUN_400eb4ac(param_1,&DAT_3f40993d,&uStack_3e);
    }
    if (!bVar1) {
      return;
    }
  } while( true );
}

