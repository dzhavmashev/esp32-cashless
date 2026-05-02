// Function : FUN_4010bb10
// Address  : 0x4010bb10
// Size     : 177 bytes


char FUN_4010bb10(int *param_1)

{
  char cVar1;
  byte bVar2;
  code *pcVar3;
  char cVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  cVar4 = '\0';
  if (param_1 != (int *)0x0) goto LAB_4010bb2c;
  pcVar7 = "ealloc: p != NULL";
  uVar6 = 0x2e0;
LAB_4010bb23:
  do {
    (*(code *)&SUB_40094c54)("if_init",uVar6,"buf_ref",pcVar7);
LAB_4010bb2c:
    while( true ) {
      FUN_4011b020();
      if (*(char *)((int)param_1 + 0xe) == '\0') break;
      cVar1 = *(char *)((int)param_1 + 0xe) + -1;
      *(char *)((int)param_1 + 0xe) = cVar1;
      memw();
      memw();
      FUN_4011b040();
      if (cVar1 != '\0') {
        return cVar4;
      }
      piVar5 = (int *)*param_1;
      if ((*(byte *)((int)param_1 + 0xd) & 2) == 0) {
        bVar2 = *(byte *)(param_1 + 3) & 0xf;
        uVar6 = 0x11;
        if (bVar2 != 2) {
          if (bVar2 != 1) {
            if ((*(byte *)(param_1 + 3) & 0xf) == 0) {
              FUN_4010afc4(param_1,param_1);
              goto LAB_4010bb73;
            }
            pcVar7 = "!= NULL";
            uVar6 = 0x318;
            goto LAB_4010bb23;
          }
          if (((param_1[4] != 0) && (param_1[5] != 0)) &&
             (pcVar3 = *(code **)(param_1[4] + 0x108), pcVar3 != (code *)0x0)) {
            (*pcVar3)();
          }
          uVar6 = 0x10;
        }
        FUN_4010b078(uVar6,param_1);
      }
      else {
        if ((code *)param_1[6] == (code *)0x0) {
          pcVar7 = "ref > 0";
          uVar6 = 0x303;
          goto LAB_4010bb23;
        }
        (*(code *)param_1[6])(param_1);
      }
LAB_4010bb73:
      cVar4 = cVar4 + '\x01';
      param_1 = piVar5;
      if (piVar5 == (int *)0x0) {
        return cVar4;
      }
    }
    pcVar7 = "uf_type";
    uVar6 = 0x2f5;
  } while( true );
}

