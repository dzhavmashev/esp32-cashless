// Function : FUN_4015fe44
// Address  : 0x4015fe44
// Size     : 172 bytes


void FUN_4015fe44(char *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 uVar3;
  
  if (*param_1 == '\0') {
    FUN_40164f34(param_1[1],*(undefined4 *)(param_1 + 4),param_1[8]);
  }
  else {
    pcVar2 = *(char **)(param_1 + 0x10);
    iVar1 = FUN_401651ac(param_1[1],*(undefined4 *)(param_1 + 4),param_1[8],param_1[9]);
    if (iVar1 != 0) {
      uVar3 = *(undefined1 *)((uint)(byte)param_1[1] * 10 + 0x3ffca1b3);
      if ((DAT_3ffc1a44 != '\0') && (((byte)param_1[1] != 0 || (memw(), DAT_3ffc1a3c == '\0')))) {
        uVar3 = DAT_3ffc7b18;
      }
      FUN_40163fb8(iVar1,param_1[10],param_1[0x16] & 3,(byte)param_1[0x16] >> 2 & 7);
      *(char *)(iVar1 + 0x82) = param_1[10];
      memw();
      if (pcVar2 != (char *)0x0) {
        *(char *)(iVar1 + 0x87) = pcVar2[1];
        memw();
        if (*pcVar2 != '\0') {
          *(undefined1 *)(iVar1 + 0x82) = 6;
          memw();
        }
      }
      memw();
      FUN_40164268(iVar1,(int)(char)((char)*(undefined4 *)(param_1 + 0xc) + '`'),uVar3,param_1[0x14]
                   ,param_1[0x15]);
      return;
    }
  }
  return;
}

