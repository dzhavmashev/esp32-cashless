// Function : FUN_400e35c0
// Address  : 0x400e35c0
// Size     : 1016 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e35c0(undefined4 *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_ec [12];
  undefined4 uStack_e0;
  undefined1 auStack_cc [12];
  undefined1 auStack_c0 [8];
  undefined1 auStack_b8 [40];
  undefined1 auStack_90 [8];
  undefined1 auStack_88 [44];
  undefined1 auStack_5c [16];
  undefined1 auStack_4c [16];
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_4c,"device_");
  uStack_3c = 0;
  FUN_400f0d4c(auStack_38,auStack_4c);
  uStack_28 = 0;
  FUN_400f0a50(auStack_4c);
  FUN_400f0be8(auStack_4c,"offline status");
  FUN_400e1680(&uStack_3c,auStack_4c,"ssfully");
  FUN_400f0a50(auStack_4c);
  FUN_400f0be8(auStack_4c,"_status");
  uVar2 = FUN_400f1a9c();
  FUN_400e189c(&uStack_3c,auStack_4c,uVar2 / 1000);
  FUN_400f0a50(auStack_4c);
  FUN_400f0be8(auStack_4c,"ime");
  uVar3 = FUN_400efe4c(0x3ffc53f4);
  FUN_400e195c(&uStack_3c,auStack_4c,uVar3);
  FUN_400f0a50(auStack_4c);
  FUN_400f0be8(auStack_4c,"ip");
  cVar1 = FUN_400e979c(&DAT_3ffc516c);
  FUN_400e1a0c(&uStack_3c,auStack_4c,(int)cVar1);
  FUN_400f0a50(auStack_4c);
  FUN_400f0be8(auStack_4c,"trieved");
  iVar4 = (*(code *)&LAB_40183e8b_1)(*(undefined4 *)(param_2 + 4));
  pcVar8 = "g state";
  if (iVar4 != 1) {
    pcVar8 = "te";
  }
  FUN_400e1680(&uStack_3c,auStack_4c,pcVar8);
  FUN_400f0a50(auStack_4c);
  FUN_400f0be8(auStack_4c,"already activated");
  uVar3 = FUN_40183e94(*(undefined4 *)(param_2 + 4));
  FUN_400e1730(&uStack_3c,auStack_4c,uVar3);
  FUN_400f0a50(auStack_4c);
  piVar6 = _DAT_3ffc405c;
  if (_DAT_3ffc405c != (int *)0x0) goto LAB_400e37a6;
  FUN_400f0be8(auStack_4c,"machine");
  *param_1 = 1;
  FUN_400f0d4c(param_1 + 1,auStack_4c);
  param_1[5] = 0;
  puVar7 = auStack_4c;
  while( true ) {
    FUN_400f0a50(puVar7);
    FUN_400e0700(&uStack_3c);
    piVar6 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400e37a6:
    uVar3 = (**(code **)(*piVar6 + 0x14))(piVar6);
    FUN_400f0be8(auStack_4c,"ic: %s\n");
    uVar3 = FUN_400e05b8(uVar3);
    FUN_400e1680(&uStack_3c,auStack_4c,uVar3);
    FUN_400f0a50(auStack_4c);
    FUN_400f0be8(auStack_4c,"ssfully");
    uVar3 = (**(code **)(*piVar6 + 0x1c))(piVar6);
    FUN_400e1730(&uStack_3c,auStack_4c,uVar3);
    FUN_400f0a50(auStack_4c);
    (**(code **)(*piVar6 + 0x18))(auStack_5c,piVar6);
    iVar4 = (*(code *)&LAB_40183a7b_1)(auStack_5c);
    if (iVar4 != 0) {
      FUN_400d7378(auStack_c0,0x200,0);
      iVar4 = FUN_400d5130(auStack_b8,auStack_5c);
      if (iVar4 == 0) {
        uVar10 = FUN_401841b0(auStack_b8);
        FUN_400d7378(auStack_90,0x200,0);
        uVar11 = FUN_400e06e4(auStack_88);
        uVar3 = (undefined4)((ulonglong)uVar11 >> 0x20);
        if ((int *)uVar10 != (int *)0x0) {
          for (iVar4 = *(int *)uVar10; iVar4 != 0; iVar4 = (*(code *)&LAB_40183a9a_2)(iVar4)) {
            iVar9 = iVar4;
            FUN_400e04f0(auStack_ec,(int)((ulonglong)uVar10 >> 0x20));
            uVar12 = FUN_40184114(auStack_cc);
            uVar5 = FUN_400e13c4((int)uVar11,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20),iVar9,
                                 uVar3);
            FUN_400e1000(uVar5,uStack_e0,uVar3);
          }
        }
        FUN_400f0be8(auStack_4c,"on_mode");
        FUN_400e1ad4(&uStack_3c,auStack_4c,(int)uVar11,uVar3);
        FUN_400f0a50(auStack_4c);
        FUN_400d73a8(auStack_90);
      }
      FUN_400d73a8(auStack_c0);
    }
    *param_1 = uStack_3c;
    FUN_400f0d04(param_1 + 1,auStack_38);
    param_1[5] = uStack_28;
    uStack_28 = 0;
    puVar7 = auStack_5c;
  }
  return;
}

