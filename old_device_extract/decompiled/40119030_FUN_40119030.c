// Function : FUN_40119030
// Address  : 0x40119030
// Size     : 79 bytes


void FUN_40119030(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 != (int *)0x0) goto LAB_40119048;
  pcVar3 = "ealloc: q != NULL";
  uVar2 = 0x896;
  do {
    while( true ) {
      (*(code *)&SUB_40094c54)("p6_frag",uVar2,"d_route",pcVar3);
LAB_40119048:
      if (param_1[1] != 0) break;
      pcVar3 = "6/nd6.c";
      uVar2 = 0x897;
    }
    while( true ) {
      piVar1 = (int *)*param_1;
      if (param_1[1] == 0) break;
      FUN_4010bb10();
      FUN_4010b078(0xe,param_1);
      param_1 = piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
    }
    pcVar3 = "sg";
    uVar2 = 0x89b;
  } while( true );
}

