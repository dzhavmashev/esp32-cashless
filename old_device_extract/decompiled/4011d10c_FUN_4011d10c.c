// Function : FUN_4011d10c
// Address  : 0x4011d10c
// Size     : 132 bytes


uint * FUN_4011d10c(uint param_1,uint param_2)

{
  char cVar1;
  uint *puVar2;
  
  puVar2 = (uint *)FUN_4010b058(7);
  if (puVar2 != (uint *)0x0) {
    *(undefined1 *)(puVar2 + 3) = 0;
    memw();
    puVar2[2] = 0;
    puVar2[7] = 0;
    *puVar2 = param_1;
    param_1 = param_1 & 0xf0;
    if (((param_1 != 0x20) && (param_1 != 0x40)) && (param_1 != 0x10)) {
      memw();
      (*(code *)&SUB_40094c54)("rgument",0x304,"nn_free","!= NULL");
    }
    cVar1 = FUN_4011ae3c(puVar2 + 4,6);
    if (cVar1 == '\0') {
      puVar2[8] = 0xffffffff;
      puVar2[5] = 0;
      puVar2[1] = 0;
      puVar2[0xf] = param_2;
      puVar2[0xe] = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0x7fffffff;
      puVar2[0xc] = 0;
      *(undefined1 *)(puVar2 + 0xd) = 0;
      memw();
      memw();
    }
    else {
      FUN_4010b078(7,puVar2);
      puVar2 = (uint *)0x0;
    }
  }
  return puVar2;
}

