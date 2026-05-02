// Function : FUN_400e30a8
// Address  : 0x400e30a8
// Size     : 1080 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e30a8(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined1 auStack_c4 [20];
  undefined1 auStack_b0 [8];
  undefined1 auStack_a8 [44];
  undefined4 auStack_7c [4];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  undefined1 auStack_4c [16];
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar2 = FUN_400d4330(param_3 + 0x18,"Missing params");
  iVar3 = FUN_400e0528();
  if (iVar3 != 0) goto LAB_400e311c;
  FUN_400f0be8(&uStack_3c,"ootTask");
  *param_1 = 1;
  FUN_400f0d4c(param_1 + 1,&uStack_3c);
  param_1[5] = 0;
  puVar8 = &uStack_3c;
  do {
    FUN_400f0a50(puVar8);
    iVar2 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
LAB_400e311c:
    iVar3 = FUN_400d48f8(iVar2,"Invalid amount");
    iVar4 = (*(code *)&LAB_401841d7_1)();
    uVar9 = 0;
    if ((iVar4 != 0) && (uVar9 = 0, iVar3 != 0)) {
      uVar9 = FUN_400e0f00(iVar3);
    }
    fVar5 = (float)(*(code *)&SUB_40002b90)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20));
    FUN_400d48f8(iVar2,"ncy");
    uVar6 = FUN_400e059c();
    FUN_400f0be8(auStack_7c,uVar6);
    if (0.0 < fVar5) {
      iVar2 = (*(code *)&LAB_40183a7b_1)(auStack_7c);
      if (iVar2 == 0) {
        FUN_400f0be8(auStack_4c," amount");
        FUN_400e6d7c(auStack_5c,0x3ffc4d78);
        uVar6 = FUN_400f10c0(auStack_4c,auStack_5c);
        uVar6 = FUN_400f10f0(uVar6,"ount");
        uVar7 = FUN_400f1a9c();
        FUN_400f0e48(&uStack_3c,uVar7,10);
        uVar6 = FUN_400f10c0(uVar6,&uStack_3c);
        FUN_400f0d18(auStack_7c,uVar6);
        FUN_400f0a50(&uStack_3c);
        FUN_400f0a50(auStack_5c);
        FUN_400f0a50(auStack_4c);
      }
      piVar1 = _DAT_3ffc405c;
      if (_DAT_3ffc405c == (int *)0x0) {
        FUN_400f0be8(&uStack_3c,"machine");
        *param_1 = 1;
        FUN_400f0d4c(param_1 + 1,&uStack_3c);
        goto LAB_400e325e;
      }
      uVar6 = (**(code **)(*_DAT_3ffc405c + 0x14))(_DAT_3ffc405c);
      (**(code **)(*piVar1 + 0xc))(piVar1,fVar5,auStack_7c);
      FUN_400f0be8(auStack_4c,"nt");
      uStack_3c = 0;
      FUN_400f0d4c(auStack_38,auStack_4c);
      uStack_28 = 0;
      FUN_400f0a50(auStack_4c);
      FUN_400f0be8(auStack_4c,"Invalid amount");
      FUN_400e1518(&uStack_3c,auStack_4c,fVar5);
      FUN_400f0a50(auStack_4c);
      FUN_400f0be8(auStack_5c,"ncy");
      FUN_400f0d4c(auStack_4c,auStack_7c);
      FUN_400e15cc(&uStack_3c,auStack_5c,auStack_4c);
      FUN_400f0a50(auStack_4c);
      FUN_400f0a50(auStack_5c);
      FUN_400f0be8(auStack_4c,"ic: %s\n");
      uVar6 = FUN_400e05b8(uVar6);
      FUN_400e1680(&uStack_3c,auStack_4c,uVar6);
      FUN_400f0a50(auStack_4c);
      FUN_400f0be8(auStack_4c,"ssfully");
      uVar6 = (**(code **)(*piVar1 + 0x1c))(piVar1);
      FUN_400e1730(&uStack_3c,auStack_4c,uVar6);
      FUN_400f0a50(auStack_4c);
      (**(code **)(*piVar1 + 0x18))(auStack_6c,piVar1);
      iVar2 = (*(code *)&LAB_40183a7b_1)(auStack_6c);
      if (iVar2 != 0) {
        FUN_400d7378(auStack_b0,0x200,0);
        iVar2 = FUN_400d5130(auStack_a8,auStack_6c);
        if (iVar2 == 0) {
          uVar9 = FUN_401841b0(auStack_a8);
          if ((int *)uVar9 != (int *)0x0) {
            for (iVar2 = *(int *)uVar9; iVar2 != 0; iVar2 = (*(code *)&LAB_40183a9a_2)(iVar2)) {
              FUN_400e04f0(auStack_c4,(int)((ulonglong)uVar9 >> 0x20),iVar2);
              FUN_400f0be8(auStack_5c,"_active");
              FUN_400f0d4c(auStack_4c,auStack_5c);
              uVar6 = FUN_400f10f0(auStack_4c);
              FUN_400e17e8(&uStack_3c,uVar6);
              FUN_400f0a50(auStack_4c);
              FUN_400f0a50(auStack_5c);
            }
          }
        }
        FUN_400d73a8(auStack_b0);
      }
      FUN_400e06b8(param_2,3,100);
      *param_1 = uStack_3c;
      FUN_400f0d04(param_1 + 1,auStack_38);
      param_1[5] = uStack_28;
      uStack_28 = 0;
      FUN_400f0a50(auStack_6c);
      FUN_400e0700(&uStack_3c);
    }
    else {
      FUN_400f0be8(&uStack_3c," params");
      *param_1 = 1;
      FUN_400f0d4c(param_1 + 1,&uStack_3c);
LAB_400e325e:
      param_1[5] = 0;
      FUN_400f0a50(&uStack_3c);
    }
    puVar8 = auStack_7c;
  } while( true );
}

