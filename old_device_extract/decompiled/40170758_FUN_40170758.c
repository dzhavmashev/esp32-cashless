// Function : FUN_40170758
// Address  : 0x40170758
// Size     : 60 bytes


void FUN_40170758(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (*(code *)&SUB_40082e0c)(*param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_40170864(4);
    *puVar2 = &DAT_3f424d24;
    FUN_401702c4(puVar2,&DAT_3f424cfc,0x401706f0);
    if (param_2 != -1) {
      FUN_401710dc(param_1);
    }
    FUN_4016ff68();
  }
  return;
}

