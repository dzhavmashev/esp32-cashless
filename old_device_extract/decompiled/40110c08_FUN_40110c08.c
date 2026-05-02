// Function : FUN_40110c08
// Address  : 0x40110c08
// Size     : 96 bytes


void FUN_40110c08(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined2 param_6,undefined2 param_7)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_4 != 0) goto LAB_40110c28;
  pcVar3 = "lid pcb";
  uVar2 = 0x7c4;
  while( true ) {
    param_2 = (*(code *)&SUB_40094c54)("lid pcb",uVar2,"_common",pcVar3);
LAB_40110c28:
    if (param_5 != 0) break;
    pcVar3 = "ocal_ip";
    uVar2 = 0x7c5;
  }
  uVar2 = FUN_40109eec(param_2);
  memw();
  iVar1 = FUN_401100f0(param_3,0,0,uVar2,param_6,param_7,0x14,0x8016);
  if (iVar1 != 0) {
    FUN_40110330();
    FUN_40110224(param_1,iVar1,param_4,param_5);
  }
  return;
}

