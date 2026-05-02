// Function : FUN_400d9cc8
// Address  : 0x400d9cc8
// Size     : 216 bytes


void FUN_400d9cc8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined1 auStack_28 [40];
  
  FUN_401845e4(auStack_28);
  iVar1 = FUN_400ec7a4(auStack_28," in SSL config",1,0);
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490," CONFIG");
  }
  else {
    uVar2 = FUN_400ecfa8(auStack_28,"ver_url");
    uVar3 = FUN_400ecfa8(auStack_28,"ay_mode");
    uVar4 = FUN_400ecfa8(auStack_28,"ev_type");
    FUN_400ec888(auStack_28);
    FUN_400f06a4(0x3ffc5490,"pen NVS");
    pcVar5 = "default";
    if (uVar2 == 0) {
      pcVar5 = "ult";
    }
    pcVar6 = "default";
    if (uVar3 == 0) {
      pcVar6 = "ult";
    }
    pcVar7 = "default";
    if (uVar4 == 0) {
      pcVar7 = "ult";
    }
    FUN_400f06a4(0x3ffc5490,"ased):\n",pcVar5,pcVar6,pcVar7);
    puVar8 = &DAT_3f401ac9;
    if (*(char *)(param_1 + 0x73) == '\0') {
      puVar8 = &DAT_3f401ace;
    }
    FUN_400f06a4(0x3ffc5490,"pin=%s\n",*(undefined1 *)(param_1 + 0x70),
                 *(undefined1 *)(param_1 + 0x71),*(undefined1 *)(param_1 + 0x72),puVar8);
    pcVar5 = "";
    if (((uVar4 | uVar2 | uVar3) & 0xff) == 0) {
      pcVar5 = " CONFIG";
    }
    FUN_400f06a4(0x3ffc5490,"Ext=%s\n",pcVar5);
  }
  FUN_400ec8a0(auStack_28);
  return;
}

