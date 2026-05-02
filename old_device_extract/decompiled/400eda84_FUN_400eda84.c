// Function : FUN_400eda84
// Address  : 0x400eda84
// Size     : 538 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400eda84(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar2 = FUN_400f13f0(param_2,0x3a);
  iVar5 = iVar2;
  if (-1 < iVar2) goto LAB_400edafd;
  uVar7 = func_0x40085c04();
  uVar3 = FUN_401847ec(&DAT_3f409fe7);
  uVar4 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
  FUN_4012105c("ent.cpp",uVar4,uVar3,0x101,"Request");
  iVar5 = 0;
  while( true ) {
    param_1 = iVar5;
    param_3 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    iVar5 = func_0x40082ecc();
LAB_400edafd:
    FUN_400f1520(auStack_34,param_2,0,iVar5);
    FUN_400f0d60(param_1 + 0x3c,auStack_34);
    FUN_400f0a50(auStack_34);
    iVar5 = FUN_400f11c0(param_1 + 0x3c,param_3);
    if (iVar5 != 0) {
      FUN_400f1760(param_2,0,iVar2 + 3);
      iVar6 = FUN_400f13f0(param_2,0x2f);
      if (iVar6 == -1) {
        iVar6 = (*(code *)&LAB_40183a7b_1)(param_2);
        FUN_400f106c(param_2,0x2f);
      }
      FUN_400f1520(auStack_54,param_2,0,iVar6);
      FUN_400f1760(param_2,0,iVar6);
      iVar6 = FUN_400f13f0(auStack_54,0x40);
      if (-1 < iVar6) {
        FUN_400f1520(auStack_44,auStack_54,0,iVar6);
        FUN_400f1760(auStack_54,0,iVar6 + 1);
        FUN_400f1938(auStack_34,auStack_44);
        FUN_400f0d60(param_1 + 0x6c,auStack_34);
        FUN_400f0a50(auStack_34);
        FUN_400f0a50(auStack_44);
      }
      iVar6 = FUN_400f13f0(auStack_54,0x3a);
      FUN_400f0be8(auStack_44,&DAT_3f42161d);
      if (iVar6 < 0) {
        FUN_400f0d18(auStack_44,auStack_54);
      }
      else {
        FUN_400f1520(auStack_34,auStack_54,0,iVar6);
        FUN_400f0d60(auStack_44,auStack_34);
        FUN_400f0a50(auStack_34);
        FUN_400f1760(auStack_54,0,iVar6 + 1);
        uVar1 = FUN_400f1854(auStack_54);
        *(undefined2 *)(param_1 + 0x1c) = uVar1;
      }
      iVar6 = FUN_400f1190(param_1 + 0xc,auStack_44);
      if ((iVar6 == 0) && (iVar6 = (*(code *)&LAB_40184637_1)(param_1), iVar6 != 0)) {
        *(undefined1 *)(param_1 + 0x9c) = 0;
        FUN_400eda0c(param_1,1);
        iVar2 = 0;
      }
      FUN_400f0d18(param_1 + 0xc,auStack_44);
      FUN_400f0d18(param_1 + 0x2c,param_2);
      FUN_400f0a50(auStack_44);
      FUN_400f0a50(auStack_54);
    }
  }
  return;
}

