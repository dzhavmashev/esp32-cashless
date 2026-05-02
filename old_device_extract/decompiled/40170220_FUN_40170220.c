// Function : FUN_40170220
// Address  : 0x40170220
// Size     : 55 bytes


int FUN_40170220(undefined *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  
  if (param_1 == (undefined *)0x0) {
    param_1 = (undefined *)0x1;
  }
  while (iVar1 = (*(code *)&SUB_40094d60)(param_1), iVar1 == 0) {
    pcVar2 = (code *)FUN_40170010();
    if (pcVar2 == (code *)0x0) {
      puVar3 = (undefined4 *)FUN_40170864(4);
      *puVar3 = &DAT_3f424c44;
      pcVar2 = (code *)FUN_401702c4(puVar3,&DAT_3f424b48,FUN_401706a4);
      param_1 = &DAT_3f424c44;
    }
    (*pcVar2)();
  }
  return iVar1;
}

