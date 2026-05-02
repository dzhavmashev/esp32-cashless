// Function : FUN_40170734
// Address  : 0x40170734
// Size     : 35 bytes


void FUN_40170734(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (*(code *)&SUB_40082de4)(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_40170864(4);
    *puVar2 = &DAT_3f424d10;
    FUN_401702c4(puVar2,"rorE",FUN_401706dc);
  }
  return;
}

