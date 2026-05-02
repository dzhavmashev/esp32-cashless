// Function : FUN_400da014
// Address  : 0x400da014
// Size     : 163 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400da014(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490," -> %d\n");
  FUN_400d988c(auStack_44,param_1[2]);
  iVar2 = (*(code *)&LAB_40183a7b_1)(auStack_44);
  iVar4 = 0x3ffc5490;
  if (iVar2 != 0) goto LAB_400da07a;
  pcVar5 = "ia WiFi";
  do {
    FUN_400f0d70(param_1 + 8,pcVar5);
    param_1 = (undefined4 *)0x0;
    while( true ) {
      FUN_400f0a50(auStack_34);
      FUN_400f0a50(auStack_44);
      iVar4 = iStack_24;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400da07a:
      puVar3 = (undefined4 *)FUN_400dbcd0(*param_1,auStack_44,auStack_34);
      if (puVar3 == (undefined4 *)0x0) break;
      param_1[6] = 1;
      *(undefined1 *)(param_1 + 7) = 1;
      cVar1 = FUN_400e979c(&DAT_3ffc516c);
      param_1[0xc] = (int)cVar1;
      FUN_400f0780(iVar4,"figured");
      param_1 = puVar3;
    }
    pcVar5 = "ssfully";
  } while( true );
}

