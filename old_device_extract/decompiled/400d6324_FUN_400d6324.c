// Function : FUN_400d6324
// Address  : 0x400d6324
// Size     : 1046 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d6324(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 auStack_174 [96];
  undefined1 auStack_114 [16];
  undefined1 auStack_104 [16];
  undefined1 auStack_f4 [16];
  undefined1 auStack_e4 [192];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400e99e8(auStack_174);
  FUN_400ee930(auStack_e4);
  iVar1 = FUN_400e6f20(0x3ffc4d78,auStack_174);
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490," JSON: ");
    param_1 = 0;
    goto LAB_400d6658;
  }
  FUN_400f0d4c(auStack_f4,param_1);
  uVar3 = FUN_400f10c0(auStack_f4,param_2);
  FUN_400f0d4c(auStack_114,uVar3);
  FUN_400f0a50(auStack_f4);
  FUN_400f0be8(auStack_f4," client");
  uVar3 = FUN_400f10c0(auStack_f4,auStack_114);
  FUN_400f0768(0x3ffc5490,uVar3);
  FUN_400f0a50(auStack_f4);
  FUN_400f0d4c(auStack_f4,auStack_114);
  iVar1 = FUN_400edcd8(auStack_e4,auStack_174,auStack_f4);
  FUN_400f0a50(auStack_f4);
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490,"ing to ");
  }
  else {
    FUN_400f0be8(auStack_104," client");
    FUN_400f0be8(auStack_f4,"nt-Type");
    FUN_400ede1c(auStack_e4,auStack_104,auStack_f4,0,1);
    FUN_400f0a50(auStack_f4);
    FUN_400f0a50(auStack_104);
    FUN_400f0be8(auStack_104,"on/json");
    FUN_400f0be8(auStack_f4,"r-Agent");
    FUN_400ede1c(auStack_e4,auStack_104,auStack_f4,0,1);
    FUN_400f0a50(auStack_f4);
    FUN_400f0a50(auStack_104);
    FUN_400eddd4(auStack_e4,10000);
    FUN_400f0d4c(auStack_f4,param_3);
    iVar2 = FUN_400efe04(auStack_e4,auStack_f4);
    FUN_400f0a50(auStack_f4);
    puVar4 = (undefined1 *)0x3ffc5490;
    if (iVar2 < 1) goto LAB_400d6694;
    FUN_400ee5f8(auStack_f4,auStack_e4);
    FUN_400f0d60(param_4,auStack_f4);
    FUN_400f0a50(auStack_f4);
    FUN_400f06a4(0x3ffc5490,"ice/1.0",iVar2);
    FUN_400eda70(auStack_e4);
    if (iVar2 == 200) goto LAB_400d6648;
    pcVar5 = "de: %d\n";
    if ((iVar2 != 0x191) && (pcVar5 = "ficates", iVar2 != 0x194)) {
      if (iVar2 != 0x199) {
        FUN_400f0be8(auStack_f4,"t found");
        FUN_400f0dd0(auStack_104,iVar2,10);
        uVar3 = FUN_400f10c0(auStack_f4,auStack_104);
        FUN_400f0d18(param_1 + 0x10,uVar3);
        FUN_400f0a50(auStack_104);
        FUN_400f0a50(auStack_f4);
        goto LAB_400d6646;
      }
      pcVar5 = "anager: Device already activated";
    }
    FUN_400f0d70(param_1 + 0x10,pcVar5);
  }
LAB_400d6646:
  while( true ) {
    iVar1 = 0;
LAB_400d6648:
    FUN_400f0a50(auStack_114);
    param_1 = iVar1;
LAB_400d6658:
    FUN_400eea5c(auStack_e4);
    FUN_400e9874(auStack_174);
    iVar2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    puVar4 = &DAT_3ffc5708;
LAB_400d6694:
    FUN_400f0be8(auStack_f4,"Error: ");
    FUN_400f0dd0(auStack_104,iVar2,10);
    uVar3 = FUN_400f10c0(auStack_f4,auStack_104);
    FUN_400f0d18(param_1 + 0x10,uVar3);
    FUN_400f0a50(auStack_104);
    FUN_400f0a50(auStack_f4);
    FUN_400f0be8(auStack_f4,"error: ");
    uVar3 = FUN_400f10c0(auStack_f4,param_1 + 0x10);
    FUN_400f0768(puVar4,uVar3);
    FUN_400f0a50(auStack_f4);
    FUN_400eda70(auStack_e4);
  }
  return;
}

